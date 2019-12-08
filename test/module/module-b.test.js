const { run } = require('../run');

test('module/module-b.js via file path', async () => expect(await run(
    './build/duke', './test/module/module-b.js'
)).toBe(0));

test('module/module-b.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/module/module-b.js'
)).toBe(0));
