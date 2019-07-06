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
$ duke a-script.js 
```

```sh
$ cat a-script.js | duke
```

### Doing Arithmetic

```sh
$ echo "1/0" | duke
```
```
⪡ Infinity
```

### Using Functions

```sh
$ echo "function id(a) { return a; }; id(1)" | duke
```
```
⪡ 1
```

### Console Logging

```sh
$ echo "console.log('message')" | duke
```
```
⪢ message
```
```
⪡ undefined
```
```sh
$ echo "console.error('message')" | duke
```
```
⫸ Error: message
```
```
⪡ undefined
```

### Throwing Errors

```sh
$ echo "throw new Error('message')" | duke
```
```
⫷ Error: message
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

### Testing

```sh
$ npm run test
```

## Copyright

 © 2019 [Hasan Karahan](https://github.com/hsk81)

---
[Duktape]: https://duktape.org/
