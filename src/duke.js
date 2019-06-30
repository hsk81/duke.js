function Duke(args) {
    this.toString = function() {
        return 'Duke: "{0}"'.replace('{0}', args.name);
    };
}

const duke = new Duke({ name: 'dracula' });
console.debug(duke.toString());
