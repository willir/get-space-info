Utility to get info about file system by directory path.
Was written to test some bugs with `boost::filesystem` usage.

## Build:

```
mkdir build/
cd build/
cmake ../
make
```

## Usage example:

```
./get_space_info /  # To print space info about file system mounted to root
./get_space_info /some/dir/path  # To print space info about file system /some/dir/path is located in.
```
