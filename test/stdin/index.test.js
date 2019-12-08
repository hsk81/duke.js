const { run } = require('../run');

test('stdin/index.js via file path', async () => expect(await run(
    'echo "console.log(1)"', '|', './build/duke', './test/stdin/index.js'
)).toBe(0));
