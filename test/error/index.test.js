const { run } = require('../run');

test('error/index.js via file path', () => run(
    './build/duke', './test/error/index.js'
).catch((code) => expect(code).toBe(1)));

test('error/index.js via std.input', () => run(
    './build/duke', '<', './test/error/index.js'
).catch((code) => expect(code).toBe(1)));
