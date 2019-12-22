const { run } = require('../run');

test('json/index.json via file path', () => run(
    './build/duke', './test/json/data.json'
).then((code) => expect(code).toBe(0)));

test('json/index.json via std.input', () => run(
    './build/duke', '<', './text/json/data.json'
).catch((code) => expect(code).toBe(1)));
