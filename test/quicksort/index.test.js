const { run } = require('../run');

test('quicksort/index.js via file path', async () => expect(await run(
    './build/duke', './test/quicksort/index.js'
)).toBe(0));

test('quicksort/index.js via std.input', async () => expect(await run(
    './build/duke', '<', './test/quicksort/index.js'
)).toBe(0));
