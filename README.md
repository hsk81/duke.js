[![NPM version](https://badge.fury.io/js/duke.js.svg)](https://npmjs.org/package/duke.js)
[![Build Status](https://app.travis-ci.com/hsk81/duke.js.svg?branch=master)](https://app.travis-ci.com/github/hsk81/duke.js)

# Duke.js: a minimal JavaScript interpreter

Duke.js is a minimal JavaScript interpreter, which has been build with [Duktape] &ndash; an embeddable and portable Javascript engine with a compact footprint. The `duke` interpreter consumes JavaScript code from a file or the standard input and then evaluates it.

## Prerequisites

```
Name            : cmake
Version         : 3.14.5-1
Description     : A cross-platform open-source make system
URL             : https://www.cmake.org/
```

## Installation

```sh
$ npm install duke.js --global
```

## Usage

### Running Scripts

```sh
$ duke ./a-script.js
```

```sh
$ duke < ./a-script.js
```

### Doing Arithmetic

```sh
$ echo "console.log(1/0)" | duke
```
```
Infinity
```

### Using Functions

```sh
$ echo "function id(a) { return a; }; console.log(id(1))" | duke
```
```
1
```

### Console Logging

```sh
$ echo "console.log('message')" | duke
```
```
message
```

```sh
$ echo "console.error('message')" | duke
```
```
Error: message
```

### Throwing Errors

```sh
$ echo "throw new Error('message')" | duke
```
```
Error: message
```

### Requiring JSON

```sh
$ cat ./data.json
```
```json
[{"0": null, "1": "1", "2": 2}]
```
```sh
$ echo "console.log(require('./data.json'))" | duke
```
```
[{"0":null,"1":"1","2":2}]
```

### Requiring Modules

```sh
$ cat ./stdout.js
```
```js
module.exports = console.log
```
```sh
$ echo "require('./stdout.js')('message')" | duke
```
```
message
```

### Reading Input

```sh
$ cat ./stdin.js
```
```js
require('/dev/stdin')
```
```sh
$ echo "console.log('message')" | duke ./stdin.js
```
```
message
```

## Development

### Cleaning

```sh
$ npm run clean
```

### Building

```sh
$ npm run build
```

### Running

```sh
$ RUN_ARGS=$PWD/test/boolean/true.js npm start
```

```sh
$ npm start < ./test/boolean/true.js
```

### Testing

```sh
$ npm test
```

## Copyright

 © 2019 [Hasan Karahan](https://github.com/hsk81)

[Duktape]: https://duktape.org/
