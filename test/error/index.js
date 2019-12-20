try {
    throw new Error('message');
} catch (e) {
    console.log(e.message);
}
