#! /bin/bash

script_dir=$(dirname $0)
cd $script_dir/build

# create release directory
mkdir -p release

# copy files to release directory
cp -r ../src release/
cp -r ../test release/
cp -r ../include release/
cp -r ../CMakeLists.txt release/
cp -r ../README.md release/

mkdir -p release/lib

cp -r *.{a,so} release/lib/


ref=$(git rev-parse --short HEAD)
echo $ref > release/commit_hash
version=$(git describe --tags)

pkging_version="v$version-$ref"


# create tarball
tar -czvf graphs-$pkging_version.tar.gz release/*

# remove release directory
rm -rf release

echo "Packaging complete"
echo "Tarball: graphs-$pkging_version.tar.gz"

echo "Signing tarball"
gpg --detach-sign graphs-$pkging_version.tar.gz
echo "Tarball signed"

echo "Creating checksum"
sha256sum graphs-$pkging_version.tar.gz > graphs-$pkging_version.tar.gz.sha256
echo "Checksum created"

# assume commands run using github actions
echo "Creating Github release"
gh release create $pkging_version graphs-$pkging_version.tar.gz graphs-$pkging_version.tar.gz.sig graphs-$pkging_version.tar.gz.sha256
echo "Github release created"


if [ ! -z "GITHUB_ACTION"  ]; then
	rm -rf $script_dir/build/graphs-$pkging_version.tar.gz
	rm -rf $script_dir/build/graphs-$pkging_version.tar.gz.sig
	rm -rf $script_dir/build/graphs-$pkging_version.tar.gz.sha256
fi

