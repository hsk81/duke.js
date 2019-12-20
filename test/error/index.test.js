const { run } = require('../run');

test('error/index.js via file path', async () => expect(await run(
    './build/duke', './test/error/index.js'
)).toBe(0));

test('error/index.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/error/index.js'
)).toBe(0));
