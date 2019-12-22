const { run, exe } = require('../run');

test('json/index.js via file path', async () => expect(await run(
    './build/duke', './test/json/index.js'
)).toBe(0));

test('json/index.js via std.input', async () => expect(await exe(
    '../../build/duke', '<', './index.js'
)({ cwd: './test/json' })).toBe(0));
