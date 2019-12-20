const { spawn } = require('child_process');

const arg = (key, lhs, rhs) => (fallback, { argv } = require('yargs')) => {
    const value = argv[key] !== undefined ? argv[key] : fallback;
    return value ? lhs === undefined ? value : lhs : rhs;
};
const exe = (cmd, ...args) => (options={}) => new Promise(
    (resolve, reject) => spawn(cmd, args, {
        shell: true, stdio: 'inherit', ...options
    }).on('exit', code =>
        (code === 0 ? resolve : reject)(code)
    )
);
module.exports = {
    arg, exe, run: (cmd, ...args) => exe(cmd, ...args)()
};
