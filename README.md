# Sorting algorithms in C

## What is this?
This repository is a little programming exercise with the goal to implement common sorting algorithms in C99. To make this a bit more fun we'll benchmark all contributions with test datasets of different size and structure to determine who wrote the fastest code :)

## Dependencies
- make >= 4.2.1
- gcc >= 9.2.0
### Optional software recommendations
- gdb >= 8.3.1 for debugging
- Visual Studio Code for development

## How to use
```
git clone https://github.com/ITSecLeibnizFH/sorting-algorithms.git
cd sorting-algorithms
make
make run
```

## How to contribute
Hey, you want to write your own sorting algorithm and have it benchmarked? Nice!

### Create a new branch
Unless you're working in a fork, please create a seperate branch for your implementation that has a distinctive name.

### Implement!
As a starting point, take a look at the reference implementation in [`src/algorithms/reference`](https://github.com/ITSecLeibnizFH/sorting-algorithms/tree/master/src/algorithms/reference) and the template files in [`src/algorithms/example`](https://github.com/ITSecLeibnizFH/sorting-algorithms/tree/master/src/algorithms/example). Implement your sorting algorithm using the template files and put it in a new folder in `src/algorithms`. After that you only need to define a `sorting_algorithm` struct that contains a pointer to your sorting function, your name and the name of your algorithm. The latter can be some well-known algorithm like `Shakersort` or something you came up with if you decided to invent a new algorithm. Add this to the list of algorithms [here](https://github.com/ITSecLeibnizFH/sorting-algorithms/tree/master/src/algos.h#L8) and you're done!

Please note that at the moment this project only supports implementations that sort **integers from small to large**, but we will extend this to other data types in the future.

## TODO
- [ ] Implement ALL the sorting algorithms
- [ ] Template standard reporting format for testing on machines with differing hardware
- [ ] Find out how to make the code generic to sort other things than integers?
- [x] Improve contribution guide
- [ ] Testdata
  - [ ] Add command line flags to only load specific testdata
  - [ ] Preload all testdata on startup