const { run } = require('../run');

test('boolean/false.js via file path', async () => expect(await run(
    './build/duke', './test/boolean/false.js'
)).toBe(0));

test('boolean/false.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/boolean/false.js'
)).toBe(0));
