const { run } = require('../run');

test('module/module-a.js via file path', async () => expect(await run(
    './build/duke', './test/module/module-a.js'
)).toBe(0));

test('module/module-a.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/module/module-a.js'
)).toBe(0));
