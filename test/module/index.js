module.exports = {
    NAME: 'index.js', VERSION: '1.0.0', MODULES: [
        require('./module-a')
    ]
};
console.log(JSON.stringify(
    module.exports, null, 2
));
