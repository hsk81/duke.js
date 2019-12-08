const { run } = require('../run');

test('dracula/index.js via file path', async () => expect(await run(
    './build/duke', './test/dracula/index.js'
)).toBe(0));

test('dracula/index.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/dracula/index.js'
)).toBe(0));
