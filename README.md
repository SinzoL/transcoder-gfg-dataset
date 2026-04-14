# TransCoder-GFG Dataset (Cleaned)

A cleaned and restructured version of the TransCoder-GFG code translation dataset originally released by Facebook AI Research.

## Overview

This dataset contains **545 parallel functions** implemented in Python, C++, and Java, collected from [GeeksforGeeks](https://www.geeksforgeeks.org/). Each function is accompanied by complete unit test cases for evaluation.

## Relationship to the Original Dataset

The original TransCoder-GFG dataset (released as part of the [TransCoder / CodeGen](https://github.com/facebookresearch/CodeGen) project) contains:

| Language | Original Files |
|----------|---------------|
| Python   | 702           |
| C++      | 698           |
| Java     | 717           |

The original files each contain: a Facebook copyright header, the reference (`f_gold`) function implementation, a `//TOFILL` placeholder for the translated function, and a `main()` / `__main__` test harness that prints `#Results: passed, total`.

### Why 545 Functions?

Not every function was available in all three languages in the original dataset. We compute the **intersection** of function names present in all three language directories, yielding **545 common functions**. Functions missing from any one language are excluded (approximately 157 functions fall into this category).

Additionally, a small number of functions are dropped during extraction if the brace-depth–tracking regex fails to isolate the `f_gold` body cleanly (e.g., due to unusual formatting).

### File Structure Changes

Each original single-file format is split into **two files** per function per language:

| File | Contents |
|------|----------|
| `FUNCTION_NAME.py` / `.cpp` / `.java` | **Extracted function only** — pure `f_gold` body, no copyright header, no `#include`/`import`, no test harness |
| `FUNCTION_NAME_full.py` / `_full.cpp` / `_full.java` | **Complete test harness** — verbatim copy of original file (header + `f_gold` + `//TOFILL` + `main()`) |

The extracted (non-`_full`) files are used as reference implementations for code translation evaluation. The `_full` files are used to run test harnesses against translated code.

## Compatibility Notes

The original dataset contains non-portable dependencies that cause compilation issues on some platforms:

| Issue | Original | Our `_full` files | Notes |
|-------|----------|-------------------|-------|
| `#include <bits/stdc++.h>` | All 698 C++ files | All 545 `_full.cpp` files | Non-standard header, unavailable on macOS/Clang |
| `import javafx.util.Pair` | All 717 Java files | All 545 `_full.java` files | Removed from JDK 11+ |

These are **not modified in the dataset files** — they remain as in the original. Evaluation scripts should handle these at runtime (e.g., by replacing `bits/stdc++.h` with explicit standard headers, and substituting `javafx.util.Pair` with a custom `Pair<F,S>` class).

## Dataset Summary

| | Original | This Dataset |
|--|----------|-------------|
| Python files | 702 (single) | 545 + 545 full |
| C++ files | 698 (single) | 545 + 545 full |
| Java files | 717 (single) | 545 + 545 full |
| Common functions | — | **545** |
| File format | Single file (header+impl+TOFILL+test) | Split: impl-only + full-test |

## Structure

```
functions/
├── python/
│   ├── FUNCTION_NAME.py          # Function implementation only (f_gold)
│   └── FUNCTION_NAME_full.py     # Function + copyright header + test harness
├── cpp/
│   ├── FUNCTION_NAME.cpp
│   └── FUNCTION_NAME_full.cpp
└── java/
    ├── FUNCTION_NAME.java
    └── FUNCTION_NAME_full.java
index.json                         # Dataset index with metadata
```

## Statistics

| Language | Functions | Avg. Lines (impl) | Avg. Test Cases |
|----------|-----------|-------------------|-----------------|
| Python   | 545       | 15.3              | 12.5            |
| C++      | 545       | 18.7              | 12.5            |
| Java     | 545       | 20.2              | 12.5            |

## Usage

Each `_full` file contains the function implementation plus a test harness that prints results in the format:

```
#Results: <passed>, <total>
```

This format is used for Computational Accuracy (CA) evaluation. To evaluate a translated function, replace the `//TOFILL` placeholder with an `f_filled` function and compile/run the `_full` file.

## Original Dataset

- **Source**: [TransCoder / CodeGen](https://github.com/facebookresearch/CodeGen) by Facebook AI Research
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

The cleaning and restructuring are released under MIT License. The original dataset follows the license of the TransCoder project.
