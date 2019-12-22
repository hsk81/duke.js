function quicksort(array) {
    if (array.length <= 1) {
        return array;
    }

    const new_array = [];
    const lhs_array = [];
    const rhs_array = [];
    const len_array = array.length;
    const tmp_pivot = array[len_array-1];

    for (var i=0; i<len_array-1; i++) {
        if (array[i] <= tmp_pivot) {
            lhs_array.push(array[i]);
        } else {
            rhs_array.push(array[i]);
        }
    }

    return new_array.concat(
        quicksort(lhs_array), tmp_pivot, quicksort(rhs_array)
    );
}

const floats = [
  "0.4739",
  "0.5471",
  "0.7253",
  "0.1613",
  "0.9890",
];

const sorted = quicksort(floats);
for (var i=0; i<sorted.length-1; i++) {
    if (sorted[i] > sorted[i+1]) {
        throw new Error('sorted[{0}] > sorted[{1}]'
            .replace('{0}', sorted.length)
            .replace('{1}', floats.length));
    }
}

if (sorted.length !== floats.length) {
    throw new Error('|sorted:{0}| !== |floats:{1}|'
        .replace('{0}', sorted.length)
        .replace('{1}', floats.length));
}
