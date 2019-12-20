const { run, exe } = require('../run');

test('module/module-b.js via file path', async () => expect(await run(
    './build/duke', './test/module/module-b.js'
)).toBe(0));

test('module/module-b.js via std.input', async () => expect(await exe(
    '../../build/duke', '<', './module-b.js'
)({ cwd: './test/module' })).toBe(0));
