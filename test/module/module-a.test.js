const { run, exe } = require('../run');

test('module/module-a.js via file path', async () => expect(await run(
    './build/duke', './test/module/module-a.js'
)).toBe(0));

test('module/module-a.js via std.input', async () => expect(await exe(
    '../../build/duke', '<', './module-a.js'
)({ cwd: './test/module' })).toBe(0));
