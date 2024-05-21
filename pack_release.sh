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


# create tarball
tar -czvf graphs-$version-$ref.tar.gz release/*

# remove release directory
rm -rf release

echo "Packaging complete"
echo "Tarball: graphs-$version-$ref.tar.gz"

echo "Signing tarball"
gpg --detach-sign graphs-$version-$ref.tar.gz
echo "Tarball signed"

echo "Creating checksum"
sha256sum graphs-$version-$ref.tar.gz > graphs-$version-$ref.tar.gz.sha256
echo "Checksum created"

# assume commands run using github actions
echo "Creating Github release"
gh release create $version-$ref graphs-$version-$ref.tar.gz graphs-$version-$ref.tar.gz.sig graphs-$version-$ref.tar.gz.sha256
echo "Github release created"


