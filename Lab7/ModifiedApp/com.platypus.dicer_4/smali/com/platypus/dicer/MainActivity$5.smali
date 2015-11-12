.class Lcom/platypus/dicer/MainActivity$5;
.super Ljava/lang/Object;
.source "MainActivity.java"

# interfaces
.implements Landroid/view/View$OnTouchListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/platypus/dicer/MainActivity;->setImageListeners()V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$0:Lcom/platypus/dicer/MainActivity;

.field final synthetic val$v:Landroid/widget/ImageView;

.field final synthetic val$vtwo:Landroid/widget/ImageView;


# direct methods
.method constructor <init>(Lcom/platypus/dicer/MainActivity;Landroid/widget/ImageView;Landroid/widget/ImageView;)V
    .locals 0

    .prologue
    .line 271
    iput-object p1, p0, Lcom/platypus/dicer/MainActivity$5;->this$0:Lcom/platypus/dicer/MainActivity;

    iput-object p2, p0, Lcom/platypus/dicer/MainActivity$5;->val$vtwo:Landroid/widget/ImageView;

    iput-object p3, p0, Lcom/platypus/dicer/MainActivity$5;->val$v:Landroid/widget/ImageView;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onTouch(Landroid/view/View;Landroid/view/MotionEvent;)Z
    .locals 2
    .param p1, "view"    # Landroid/view/View;
    .param p2, "motionEvent"    # Landroid/view/MotionEvent;

    .prologue
    .line 274
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$5;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v0}, Lcom/platypus/dicer/MainActivity;->playDieSound()V

    .line 275
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$5;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v0}, Lcom/platypus/dicer/MainActivity;->vibrate()V

    .line 276
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$5;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v0}, Lcom/platypus/dicer/MainActivity;->playDieSound()V

    .line 277
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$5;->this$0:Lcom/platypus/dicer/MainActivity;

    iget-object v1, p0, Lcom/platypus/dicer/MainActivity$5;->val$vtwo:Landroid/widget/ImageView;

    invoke-virtual {v0, v1}, Lcom/platypus/dicer/MainActivity;->shuffleImage(Landroid/widget/ImageView;)V

    .line 278
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$5;->this$0:Lcom/platypus/dicer/MainActivity;

    iget-object v1, p0, Lcom/platypus/dicer/MainActivity$5;->val$v:Landroid/widget/ImageView;

    invoke-virtual {v0, v1}, Lcom/platypus/dicer/MainActivity;->shuffleImage(Landroid/widget/ImageView;)V

    .line 279
    const/4 v0, 0x0

    return v0
.end method
