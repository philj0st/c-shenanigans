# c-shenanigans
just me implementing some stuff in C

did some stupid lisp-inspired things like [`car` and `cdr`](https://en.wikipedia.org/wiki/CAR_and_CDR).
allowing for lisp-like c code i.e `Pair* newList = cons(2, cons(4, cons(12, cons(24, cons(48, NULL)))));`

### Watch

added watch.js to watch for changes in \*.c files and automatically compile and run them.

to use the watch script run `npm install` to install dependencies and then start it with `node watch.js` (assuming you have `node` and `npm` installed)
