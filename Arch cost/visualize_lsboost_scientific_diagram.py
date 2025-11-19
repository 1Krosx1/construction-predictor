"""
Generate a complex, multi-panel scientific-style diagram of the LSBoost model.

This script creates a three-part figure to explain the architectural model:
- Panel A: The data preprocessing and feature engineering pipeline.
- Panel B: The core LSBoost ensemble mechanism and hyperparameters.
- Panel C: Feature importance and the final prediction transformation.
"""
import matplotlib.pyplot as plt
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch, PathPatch
from matplotlib.path import Path as MplPath
from pathlib import Path
import numpy as np

# --- Style Configuration ---
BOX_STYLE = dict(boxstyle="round,pad=0.02", linewidth=1.2, edgecolor="#3b5998", facecolor="#dfe3ee")
ARROW_STYLE = dict(arrowstyle="->", mutation_scale=15, linewidth=1.4, color="#333333")
TEXT_STYLE = dict(ha="center", va="center", fontsize=9, color="#1c1e21")
PANEL_LABEL_STYLE = dict(fontsize=14, fontweight='bold', ha='left', va='bottom')

def add_box(ax, xy, width, height, text, **kwargs):
    """Draw a styled rounded box with text."""
    style = {**TEXT_STYLE, **kwargs}
    ax.add_patch(FancyBboxPatch(xy, width, height, **BOX_STYLE))
    ax.text(xy[0] + width / 2, xy[1] + height / 2, text, **style)

def add_arrow(ax, start, end, **kwargs):
    """Draw a styled arrow."""
    ax.add_patch(FancyArrowPatch(start, end, **ARROW_STYLE, **kwargs))

def draw_tree(ax, origin, scale=1):
    """Draw a simplified decision tree shape."""
    verts = [
        (origin[0], origin[1]),  # root
        (origin[0] - 0.2*scale, origin[1] - 0.3*scale),  # left child
        (origin[0] + 0.2*scale, origin[1] - 0.3*scale),  # right child
        (origin[0], origin[1]), # move back to root
        (origin[0] - 0.4*scale, origin[1] - 0.6*scale),
        (origin[0], origin[1] - 0.6*scale),
        (origin[0] - 0.2*scale, origin[1] - 0.3*scale),
        (origin[0], origin[1] - 0.6*scale),
        (origin[0] + 0.2*scale, origin[1] - 0.3*scale),
        (origin[0] + 0.4*scale, origin[1] - 0.6*scale),
    ]
    codes = [MplPath.MOVETO, MplPath.LINETO, MplPath.LINETO, MplPath.MOVETO, MplPath.LINETO, MplPath.LINETO, MplPath.MOVETO, MplPath.LINETO, MplPath.MOVETO, MplPath.LINETO]
    path = MplPath(verts, codes)
    patch = PathPatch(path, facecolor='none', lw=1, edgecolor='#3b5998')
    ax.add_patch(patch)

def panel_a(ax):
    """Panel A: Data Flow and Feature Transformation Pipeline."""
    ax.set_title("(a) Data Transformation Pipeline", loc='left', fontdict={'fontsize': 12, 'fontweight': 'bold'})
    ax.set_xlim(0, 10)
    ax.set_ylim(0, 6)
    ax.axis('off')

    # Initial Data
    add_box(ax, (0.5, 4.5), 2.5, 1, "Raw Data Source\n`Architectural_Total_Cost.csv`")
    add_arrow(ax, (1.75, 4.5), (1.75, 3.7))

    # Cleaning & Engineering
    add_box(ax, (0.5, 2.5), 2.5, 1.2, "1. Cleaning & Engineering\n- Median Imputation\n- Regex `num_storeys`\n- Create `total_chb_area`")
    add_arrow(ax, (3, 3.1), (4, 3.1))

    # Polynomial Expansion
    add_box(ax, (4, 2.5), 2.5, 1.2, "2. Polynomial Expansion\n- Degree 2\n- $x_i \\rightarrow [x_i, x_i^2, x_i x_j]$\n- 10 to 65 features")
    add_arrow(ax, (6.5, 3.1), (7.5, 3.1))

    # Scaling and Selection
    add_box(ax, (7.5, 2.5), 2.5, 1.2, "3. Scaling & Selection\n- Z-score with train $(\\mu, \\sigma)$\n- Importance mask\n- 32 features remain")
    
    # Final Output
    add_arrow(ax, (5, 2.5), (5, 1.7))
    add_box(ax, (3.75, 0.5), 2.5, 1.2, "Final Feature Matrix\n$Z_{sel}$")

def panel_b(ax):
    """Panel B: Core LSBoost Ensemble Mechanism."""
    ax.set_title("(b) LSBoost Ensemble Architecture", loc='left', fontdict={'fontsize': 12, 'fontweight': 'bold'})
    ax.set_xlim(0, 10)
    ax.set_ylim(0, 6)
    ax.axis('off')

    # Initial model
    ax.text(1.5, 5, "$F_0(x) = \\bar{y}$", **TEXT_STYLE)
    draw_tree(ax, (1.5, 4), scale=1.5)
    ax.text(1.5, 3.2, "Tree $f_1(x)$", **TEXT_STYLE)
    add_arrow(ax, (2.5, 4), (3.5, 4))
    ax.text(3, 4.3, "predicts $y$", **TEXT_STYLE)

    # Residual calculation
    add_box(ax, (3.5, 3.5), 2, 1, "Residual\n$r_1 = y - \\eta f_1(x)$")
    add_arrow(ax, (5.5, 4), (6.5, 4))
    ax.text(6, 4.3, "is target for", **TEXT_STYLE)

    # Next tree
    draw_tree(ax, (7.5, 4), scale=1.5)
    ax.text(7.5, 3.2, "Tree $f_2(x)$", **TEXT_STYLE)
    
    # Iteration
    ax.text(5, 2.5, "Process repeats for $t = 1, ..., T$ trees (T ≈ 700)", ha="center", va="center", fontsize=10, color="#1c1e21")
    add_arrow(ax, (7.5, 3.2), (7.5, 2.2), connectionstyle="arc3,rad=-0.3")
    add_arrow(ax, (1.5, 3.2), (1.5, 2.2), connectionstyle="arc3,rad=0.3")
    
    # Final Model
    add_box(ax, (3, 0.5), 4, 1.2, "Final Model: $F_T(x) = \\sum_{t=1}^{T} \\eta f_t(x)$\n(Shrinkage $\\eta$ is LearnRate ≈ 0.1)")

def panel_c(ax):
    """Panel C: Feature Importance and Prediction."""
    ax.set_title("(c) Feature Importance & Prediction", loc='left', fontdict={'fontsize': 12, 'fontweight': 'bold'})
    ax.set_xlim(0, 10)
    ax.set_ylim(0, 6)
    ax.axis('off')

    # Feature Importance
    ax.text(2.5, 5.5, "Top Feature Importances", **TEXT_STYLE, fontweight='bold')
    importances = {'$year * num\_cl$': 0.15, '$total\_chb^2$': 0.12, '$plaster\_per\_chb$': 0.1, '$year^2$': 0.08, '...': 0.05}
    y_pos = np.arange(len(importances))
    ax.barh(y_pos, importances.values(), height=0.6, align='center', color="#8b9dc3")
    ax.set_yticks(y_pos, labels=importances.keys())
    ax.set_xlabel("Predictor Importance (Gain)", fontsize=9)
    ax.tick_params(axis='both', which='major', labelsize=9)
    ax.set_ylim(len(importances)-0.5, -0.5) # Invert y-axis
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    # Prediction
    add_arrow(ax, (5, 3), (6, 3))
    add_box(ax, (6, 2.25), 3.5, 1.5, "Prediction Transformation\n1. Predict in log space:\n$\\hat{y}_{log} = F_T(Z_{sel})$\n2. Invert to get budget:\n$\\widehat{Budget} = \\exp(\\hat{y}_{log}) - 1$")

def main():
    """Main function to create and save the figure."""
    fig = plt.figure(figsize=(12, 8), constrained_layout=True)
    fig.suptitle("LSBoost Model Architecture for Architectural Budget Prediction", fontsize=16, fontweight='bold', color="#1c1e21")

    # Create a 2x2 grid specification
    gs = fig.add_gridspec(2, 2)

    # Panel A in the top-left
    ax_a = fig.add_subplot(gs[0, :])
    panel_a(ax_a)

    # Panel B in the bottom-left
    ax_b = fig.add_subplot(gs[1, 0])
    panel_b(ax_b)

    # Panel C in the bottom-right
    ax_c = fig.add_subplot(gs[1, 1])
    panel_c(ax_c)

    # Save the figure
    output_dir = Path(__file__).resolve().parent / "visualizations"
    output_dir.mkdir(parents=True, exist_ok=True)
    output_path = output_dir / "architectural_lsboost_scientific_diagram.png"
    fig.savefig(output_path, dpi=300, bbox_inches="tight")
    print(f"Saved complex scientific diagram to {output_path}")

if __name__ == "__main__":
    main()
