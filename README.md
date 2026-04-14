# TransCoder-GFG Dataset (Cleaned)

A cleaned and verified version of the TransCoder-GFG code translation dataset originally released by Facebook AI Research.

## Overview

This dataset contains **545 parallel functions** implemented in Python, C++, and Java, collected from [GeeksforGeeks](https://www.geeksforgeeks.org/). Each function is accompanied by complete unit test cases for evaluation.

## Cleaning & Fixes

The original dataset contained several issues that were manually identified and fixed:

- **Test output format inconsistencies**: Unified the `#Results: passed, total` output format across all languages
- **Semantic mismatches**: Corrected functions where implementations in different languages were not semantically equivalent
- **Nested type parsing errors**: Fixed issues with complex nested type signatures (e.g., `vector<pair<int,int>>`)
- **Java compatibility**: Fixed `javafx.util.Pair` imports (removed from JDK 11+) with custom implementations
- **C++ compatibility**: Replaced `#include <bits/stdc++.h>` with explicit standard headers for macOS/clang compatibility

## Structure

```
functions/
├── python/
│   ├── FUNCTION_NAME.py          # Function implementation
│   └── FUNCTION_NAME_full.py     # Function + test harness
├── cpp/
│   ├── FUNCTION_NAME.cpp
│   └── FUNCTION_NAME_full.cpp
└── java/
    ├── FUNCTION_NAME.java
    └── FUNCTION_NAME_full.java
index.json                         # Dataset index with metadata
```

## Statistics

| Language | Functions | Avg. Lines | Avg. Test Cases |
|----------|-----------|------------|-----------------|
| Python   | 545       | 15.3       | 12.5            |
| C++      | 545       | 18.7       | 12.5            |
| Java     | 545       | 20.2       | 12.5            |

## Usage

Each `_full` file contains the function implementation plus a test harness that prints results in the format:

```
#Results: <passed>, <total>
```

This format is used for Computational Accuracy (CA) evaluation.

## Original Dataset

- **Source**: [TransCoder](https://github.com/facebookresearch/CodeGen) by Facebook AI Research
- **Paper**: Roziere et al., "Unsupervised Translation of Programming Languages", NeurIPS 2020
- **Data origin**: GeeksforGeeks programming problems

## Citation

If you use this dataset, please cite the original TransCoder paper:

```bibtex
@inproceedings{roziere2020unsupervised,
  title={Unsupervised Translation of Programming Languages},
  author={Roziere, Baptiste and Lachaux, Marie-Anne and Chanussot, Lowik and Lample, Guillaume},
  booktitle={Advances in Neural Information Processing Systems},
  volume={33},
  pages={20601--20611},
  year={2020}
}
```

## License

The cleaning and fixes are released under MIT License. The original dataset follows the license of the TransCoder project.
