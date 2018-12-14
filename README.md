# DGaussGen

A tool that generate a list of normally distributed values in json format. Since it is a compiled c++ program it should be fast.

## Requirements
* g++ compiler
## Install
Just stand in the repos root and run:
```bash
./build.sh  [OPTIONS]
```
This will generate the binary dgauss_gen

### Available build options
```bash
-u|--mean-default) Changes mean default value, if not set default is 0
-d|--std-default) Changes standard deviation default value, if not set default is 1
-u|--limit-default) Number of values that will be generated, if not set default is 10
```

# Usage

Just type the following to generate values according to default values with a seed based on time.

```bash
./dgauss_gen
```

For a help text:
```bash
./dgauss_gen -h
```
