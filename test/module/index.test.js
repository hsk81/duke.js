const { run } = require('../run');

test('module/index.js via file path', async () => expect(await run(
    './build/duke', './test/module/index.js'
)).toBe(0));

test('module/index.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/module/index.js'
)).toBe(0));
