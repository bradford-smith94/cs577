.class Lcom/platypus/dicer/MainActivity$2;
.super Ljava/lang/Object;
.source "MainActivity.java"

# interfaces
.implements Landroid/view/View$OnClickListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/platypus/dicer/MainActivity;->setLayout()V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$0:Lcom/platypus/dicer/MainActivity;

.field final synthetic val$button:Landroid/widget/Button;


# direct methods
.method constructor <init>(Lcom/platypus/dicer/MainActivity;Landroid/widget/Button;)V
    .locals 0

    .prologue
    .line 200
    iput-object p1, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    iput-object p2, p0, Lcom/platypus/dicer/MainActivity$2;->val$button:Landroid/widget/Button;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onClick(Landroid/view/View;)V
    .locals 9
    .param p1, "v"    # Landroid/view/View;

    .prologue
    const v8, 0x7f0b0042

    const v7, 0x7f0b0040

    const v6, 0x7f0b003f

    const/4 v5, 0x4

    const/4 v4, 0x0

    .line 202
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    iget-boolean v2, v2, Lcom/platypus/dicer/MainActivity;->showDice:Z

    if-eqz v2, :cond_0

    .line 203
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    iput-boolean v4, v2, Lcom/platypus/dicer/MainActivity;->showDice:Z

    .line 204
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v6}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/ImageView;

    .line 205
    .local v0, "image":Landroid/widget/ImageView;
    invoke-virtual {v0, v5}, Landroid/widget/ImageView;->setVisibility(I)V

    .line 207
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v7}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    .end local v0    # "image":Landroid/widget/ImageView;
    check-cast v0, Landroid/widget/ImageView;

    .line 208
    .restart local v0    # "image":Landroid/widget/ImageView;
    invoke-virtual {v0, v5}, Landroid/widget/ImageView;->setVisibility(I)V

    .line 210
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->val$button:Landroid/widget/Button;

    const v3, 0x7f0d0015

    invoke-virtual {v2, v3}, Landroid/widget/Button;->setText(I)V

    .line 211
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v8}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/Button;

    .line 212
    .local v1, "roll_button":Landroid/widget/Button;
    invoke-virtual {v1, v4}, Landroid/widget/Button;->setVisibility(I)V

    .line 213
    new-instance v2, Lcom/platypus/dicer/MainActivity$2$1;

    invoke-direct {v2, p0}, Lcom/platypus/dicer/MainActivity$2$1;-><init>(Lcom/platypus/dicer/MainActivity$2;)V

    invoke-virtual {v1, v2}, Landroid/widget/Button;->setOnClickListener(Landroid/view/View$OnClickListener;)V

    .line 237
    :goto_0
    return-void

    .line 224
    .end local v0    # "image":Landroid/widget/ImageView;
    .end local v1    # "roll_button":Landroid/widget/Button;
    :cond_0
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    const/4 v3, 0x1

    iput-boolean v3, v2, Lcom/platypus/dicer/MainActivity;->showDice:Z

    .line 225
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v6}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/ImageView;

    .line 226
    .restart local v0    # "image":Landroid/widget/ImageView;
    invoke-virtual {v0, v4}, Landroid/widget/ImageView;->setVisibility(I)V

    .line 228
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v7}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    .end local v0    # "image":Landroid/widget/ImageView;
    check-cast v0, Landroid/widget/ImageView;

    .line 229
    .restart local v0    # "image":Landroid/widget/ImageView;
    invoke-virtual {v0, v4}, Landroid/widget/ImageView;->setVisibility(I)V

    .line 231
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->val$button:Landroid/widget/Button;

    const v3, 0x7f0d0013

    invoke-virtual {v2, v3}, Landroid/widget/Button;->setText(I)V

    .line 233
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v8}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/Button;

    .line 234
    .restart local v1    # "roll_button":Landroid/widget/Button;
    invoke-virtual {v1, v5}, Landroid/widget/Button;->setVisibility(I)V

    goto :goto_0
.end method
