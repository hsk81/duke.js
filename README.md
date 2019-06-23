# Duke.js: a minimal JavaScript interpreter

Duke.js is a minimal JavaScript interpreter, which has been build with [Duktape] &ndash; an embeddable and portable Javascript engine with a compact footprint. The `duke` interpreter consumes a single line of JavaScript code and then executes it, while it's possible to run an entire script by having it (automatically) minified.

## Prerequisites

```
Name            : cmake
Version         : 3.14.5-1
Description     : A cross-platform open-source make system
URL             : https://www.cmake.org/
```

```
Name            : duktape
Version         : 2.3.0-2
Description     : Embeddable Javascript engine
URL             : https://duktape.org/
```

## Installation

```sh
npm install
```

## Development

### Building

```sh
npm run build
```

### Cleaning

```sh
npm run clean
```

## Usage

### Doing Arithmetic

```sh
echo "1/0" | npm start
```
```
⪡ Infinity
```

### Using Functions

```sh
echo "function id(a) { return a; }; id(1)" | npm start
```
```
⪡ 1
```

### Simple Logging

```sh
echo "log('message')" | npm start
```
```
⪢ message
```
```
⪡ undefined
```

### Throwing Errors

```sh
echo "throw new Error('message')" | npm start
```
```
⫷ Error: message
```

### Running Scripts

```sh
cat ./src/duke.js | npm start ## or:
```
```sh
npm start < ./src/duke.js
```
```
> duke@1.0.0 start ~
> npx terser | ./build/duke
```
```
⪢ Duke: "dracula"
```
```
⪡ undefined
```

[Duktape]: https://duktape.org/

## Copyright

 © 2019 [Hasan Karahan](https://github.com/hsk81)
