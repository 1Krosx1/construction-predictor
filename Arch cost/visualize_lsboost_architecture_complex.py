"""Render a richer diagram of the architectural LSBoost training setup.

The figure mimics multi-panel scientific schematics: panel (a) highlights the
pre-processing workflow, panel (b) tabulates the tuned hyperparameters, and
panel (c) sketches the sequential boosting cycle with residual corrections.
"""

import matplotlib.pyplot as plt
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch
from pathlib import Path


def add_box(ax, xy, width, height, text, fontsize=11, bold=False):
    """Draw a rounded rectangle with centered text."""
    box = FancyBboxPatch(
        xy,
        width,
        height,
        boxstyle="round,pad=0.015",
        linewidth=1.3,
        edgecolor="#204060",
        facecolor="#e6eef8",
    )
    ax.add_patch(box)
    ax.text(
        xy[0] + width / 2.0,
        xy[1] + height / 2.0,
        text,
        ha="center",
        va="center",
        fontsize=fontsize,
        fontweight="bold" if bold else "normal",
        color="#152235",
    )


def add_arrow(ax, start, end, text=None, text_offset=(0, 0)):
    """Add an arrow between two points with optional annotation."""
    arrow = FancyArrowPatch(
        start,
        end,
        arrowstyle="->",
        mutation_scale=12,
        linewidth=1.3,
        color="#444",
    )
    ax.add_patch(arrow)
    if text:
        ax.text(
            (start[0] + end[0]) / 2.0 + text_offset[0],
            (start[1] + end[1]) / 2.0 + text_offset[1],
            text,
            fontsize=10,
            ha="center",
            va="center",
            color="#333",
        )


def panel_a(ax):
    ax.axis("off")
    ax.set_xlim(0, 10)
    ax.set_ylim(0, 4)

    add_box(ax, (0.2, 1.25), 1.8, 1.5, "Raw CSV\n(Architectural_Total_Cost)", bold=True)
    add_box(ax, (2.3, 1.25), 1.8, 1.5, "Cleaning\n• Header normalization\n• Median imputation")
    add_box(ax, (4.4, 1.25), 1.9, 1.5, "Feature Engineering\n• Regex storeys/classrooms\n• Totals & ratios")
    add_box(ax, (6.7, 1.25), 1.8, 1.5, "Polynomial Expansion\nDegree 2 (65 terms)")
    add_box(ax, (8.8, 1.25), 1.8, 1.5, "Scaling + Mask\nZ-score + importance filter")

    add_arrow(ax, (1.99, 2.0), (2.30, 2.0))
    add_arrow(ax, (4.10, 2.0), (4.40, 2.0))
    add_arrow(ax, (6.30, 2.0), (6.70, 2.0))
    add_arrow(ax, (8.50, 2.0), (8.80, 2.0))

    add_arrow(ax, (9.70, 2.0), (10.5, 2.0), text="LSBoost ensemble", text_offset=(0.0, 0.3))
    add_box(
        ax,
        (10.5, 1.25),
        1.8,
        1.5,
        "LSBoost\n~700 shallow trees\nLearn rate ≈ 0.1",
    )
    ax.text(0, 3.6, "(a) Data preparation and feature pipeline", fontsize=12, fontweight="bold")


def panel_b(ax):
    ax.axis("off")
    table_data = [
        ["Hyperparameter", "Tuned range", "Selected value"],
        ["NumLearningCycles", "[500, 1000]", "≈ 714"],
        ["MaxNumSplits", "[8, 32]", "8"],
        ["LearnRate", "[0.01, 0.1] (log)", "≈ 0.10"],
    ]
    tbl = ax.table(
        cellText=table_data,
        colLabels=None,
        cellLoc="center",
        loc="center",
        colWidths=[0.34, 0.33, 0.33],
    )
    tbl.auto_set_font_size(False)
    tbl.set_fontsize(10)
    for (row, col), cell in tbl.get_celld().items():
        cell.set_edgecolor("#204060")
        if row == 0:
            cell.set_text_props(fontweight="bold", color="white")
            cell.set_facecolor("#2e4a6d")
        else:
            cell.set_facecolor("#eef3fb")
    ax.text(0.0, 0.95, "(b) Hyperparameter search summary", fontsize=12, fontweight="bold")


def panel_c(ax):
    ax.axis("off")
    ax.set_xlim(0, 12)
    ax.set_ylim(0, 5)
    ax.text(0, 4.7, "(c) LSBoost cycle: residual fitting", fontsize=12, fontweight="bold")

    # Stage 1
    add_box(ax, (0.3, 3.3), 2.2, 1.1, "Stage 1\nInitial tree f₁(x)")
    add_arrow(ax, (2.5, 3.85), (3.3, 3.85), text="Predict", text_offset=(0.0, 0.25))
    add_box(ax, (3.3, 3.3), 2.1, 1.1, "Residual r₁ = y − f₁(x)")

    # Stage 2
    add_arrow(ax, (5.4, 3.85), (6.2, 3.85), text="Fit", text_offset=(0.0, 0.25))
    add_box(ax, (6.2, 3.3), 2.2, 1.1, "Stage 2\nTree g₂(x) ≈ r₁")
    add_arrow(ax, (8.4, 3.85), (9.2, 3.85))
    add_box(ax, (9.2, 3.3), 2.1, 1.1, "Update F₂ = f₁ + η·g₂")

    # Stage 3
    add_arrow(ax, (2.5, 1.80), (3.3, 1.80))
    add_box(ax, (0.3, 1.25), 2.2, 1.1, "Stage t\nTree g_t(x)")
    add_box(ax, (3.3, 1.25), 2.1, 1.1, "Residual r_{t−1}" )
    add_arrow(ax, (5.4, 1.80), (6.2, 1.80))
    add_box(ax, (6.2, 1.25), 2.2, 1.1, "Shrink update\nF_t = F_{t−1} + η·g_t")
    add_arrow(ax, (8.4, 1.80), (9.2, 1.80))
    add_box(ax, (9.2, 1.25), 2.1, 1.1, "Iterate until\ncycles ≈ 700")

    ax.text(
        0.3,
        0.5,
        "Each shallow tree reduces remaining error.\nValidation set controls early stopping via importance mask.",
        fontsize=10,
        color="#333",
    )


def main() -> None:
    fig = plt.figure(figsize=(14, 10))
    gs = fig.add_gridspec(2, 2, height_ratios=[1, 1.2])

    ax_a = fig.add_subplot(gs[0, 0])
    panel_a(ax_a)

    ax_b = fig.add_subplot(gs[0, 1])
    panel_b(ax_b)

    ax_c = fig.add_subplot(gs[1, :])
    panel_c(ax_c)

    fig.suptitle(
        "Architectural LSBoost Training Architecture",
        fontsize=16,
        color="#1b2d42",
        y=0.96,
    )

    output_dir = Path(__file__).resolve().parent / "visualizations"
    output_dir.mkdir(parents=True, exist_ok=True)
    output_path = output_dir / "architectural_lsboost_pipeline_complex.png"
    fig.savefig(output_path, dpi=200, bbox_inches="tight")
    print(f"Saved complex architecture diagram to {output_path}")


if __name__ == "__main__":
    main()
