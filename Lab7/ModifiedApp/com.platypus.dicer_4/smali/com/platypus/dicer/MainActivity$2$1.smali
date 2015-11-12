.class Lcom/platypus/dicer/MainActivity$2$1;
.super Ljava/lang/Object;
.source "MainActivity.java"

# interfaces
.implements Landroid/view/View$OnClickListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/platypus/dicer/MainActivity$2;->onClick(Landroid/view/View;)V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$1:Lcom/platypus/dicer/MainActivity$2;


# direct methods
.method constructor <init>(Lcom/platypus/dicer/MainActivity$2;)V
    .locals 0

    .prologue
    .line 213
    iput-object p1, p0, Lcom/platypus/dicer/MainActivity$2$1;->this$1:Lcom/platypus/dicer/MainActivity$2;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onClick(Landroid/view/View;)V
    .locals 4
    .param p1, "v"    # Landroid/view/View;

    .prologue
    .line 215
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2$1;->this$1:Lcom/platypus/dicer/MainActivity$2;

    iget-object v2, v2, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2}, Lcom/platypus/dicer/MainActivity;->playDieSound()V

    .line 216
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2$1;->this$1:Lcom/platypus/dicer/MainActivity$2;

    iget-object v2, v2, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2}, Lcom/platypus/dicer/MainActivity;->vibrate()V

    .line 217
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2$1;->this$1:Lcom/platypus/dicer/MainActivity$2;

    iget-object v2, v2, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    const v3, 0x7f0b003f

    invoke-virtual {v2, v3}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/ImageView;

    .line 218
    .local v0, "dice1":Landroid/widget/ImageView;
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2$1;->this$1:Lcom/platypus/dicer/MainActivity$2;

    iget-object v2, v2, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    const v3, 0x7f0b0040

    invoke-virtual {v2, v3}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/ImageView;

    .line 219
    .local v1, "dice2":Landroid/widget/ImageView;
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2$1;->this$1:Lcom/platypus/dicer/MainActivity$2;

    iget-object v2, v2, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v0}, Lcom/platypus/dicer/MainActivity;->shuffleImage(Landroid/widget/ImageView;)V

    .line 220
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$2$1;->this$1:Lcom/platypus/dicer/MainActivity$2;

    iget-object v2, v2, Lcom/platypus/dicer/MainActivity$2;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2, v1}, Lcom/platypus/dicer/MainActivity;->shuffleImage(Landroid/widget/ImageView;)V

    .line 221
    return-void
.end method
