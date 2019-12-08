const { spawn } = require('child_process');

const arg = (key, lhs, rhs) => (fallback, { argv } = require('yargs')) => {
    const value = argv[key] !== undefined ? argv[key] : fallback;
    return value ? lhs === undefined ? value : lhs : rhs;
};
const run = (command, ...args) => new Promise(
    (resolve, reject) => spawn(command, args, {
        shell: true, stdio: 'inherit'
    }).on('exit', code =>
        (code === 0 ? resolve : reject)(code)
    )
);
module.exports = {
    arg, run
};
