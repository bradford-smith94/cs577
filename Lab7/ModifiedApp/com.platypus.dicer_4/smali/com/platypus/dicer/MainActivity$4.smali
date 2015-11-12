.class Lcom/platypus/dicer/MainActivity$4;
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
    .line 259
    iput-object p1, p0, Lcom/platypus/dicer/MainActivity$4;->this$0:Lcom/platypus/dicer/MainActivity;

    iput-object p2, p0, Lcom/platypus/dicer/MainActivity$4;->val$vtwo:Landroid/widget/ImageView;

    iput-object p3, p0, Lcom/platypus/dicer/MainActivity$4;->val$v:Landroid/widget/ImageView;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onTouch(Landroid/view/View;Landroid/view/MotionEvent;)Z
    .locals 2
    .param p1, "view"    # Landroid/view/View;
    .param p2, "motionEvent"    # Landroid/view/MotionEvent;

    .prologue
    .line 262
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$4;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v0}, Lcom/platypus/dicer/MainActivity;->playDieSound()V

    .line 263
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$4;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v0}, Lcom/platypus/dicer/MainActivity;->vibrate()V

    .line 264
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$4;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v0}, Lcom/platypus/dicer/MainActivity;->playDieSound()V

    .line 265
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$4;->this$0:Lcom/platypus/dicer/MainActivity;

    iget-object v1, p0, Lcom/platypus/dicer/MainActivity$4;->val$vtwo:Landroid/widget/ImageView;

    invoke-virtual {v0, v1}, Lcom/platypus/dicer/MainActivity;->shuffleImage(Landroid/widget/ImageView;)V

    .line 266
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity$4;->this$0:Lcom/platypus/dicer/MainActivity;

    iget-object v1, p0, Lcom/platypus/dicer/MainActivity$4;->val$v:Landroid/widget/ImageView;

    invoke-virtual {v0, v1}, Lcom/platypus/dicer/MainActivity;->shuffleImage(Landroid/widget/ImageView;)V

    .line 267
    const/4 v0, 0x0

    return v0
.end method
