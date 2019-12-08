const { run } = require('../run');

test('module/module-c.js via file path', async () => expect(await run(
    './build/duke', './test/module/module-c.js'
)).toBe(0));

test('module/module-c.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/module/module-c.js'
)).toBe(0));
