# cicd-integration

A small C project used to exercise the **DefectSight quality gate** in a
real CI pipeline.

This repository is the *consumer* side of the integration. It contains no
DefectSight code — the gate is fetched at run time by the workflow in
`.github/workflows/defect-gate.yml`.

## What it demonstrates

On every pull request:

1. The gate diffs `base...head` to find changed C files
2. Extracts per-function static metrics (McCabe, Halstead, LOC family)
3. Scores each changed function with a trained champion model
4. Explains each score with SHAP
5. Aggregates to a commit-level risk score and a verdict

Only **changed** functions are scored — untouched code is never
re-flagged, so a PR is never blocked for pre-existing debt its author
did not write.

## Layout

```
include/orders.h    shared declarations
src/billing.c       pricing and discounts
src/inventory.c     stock checks
src/util.c          small helpers
```

## Note on risk scores

The gate reports a *risk score*, used to rank relative risk. It is not a
calibrated probability, and a high score is not proof of a defect — it
indicates structural complexity that correlates with defects.
