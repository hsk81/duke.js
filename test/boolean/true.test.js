const { run } = require('../run');

test('boolean/true.js via file path', async () => expect(await run(
    './build/duke', './test/boolean/true.js'
)).toBe(0));

test('boolean/true.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/boolean/true.js'
)).toBe(0));
