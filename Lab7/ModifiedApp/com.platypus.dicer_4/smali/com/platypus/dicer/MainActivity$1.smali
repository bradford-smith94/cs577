.class Lcom/platypus/dicer/MainActivity$1;
.super Ljava/lang/Object;
.source "MainActivity.java"

# interfaces
.implements Lcom/platypus/dicer/ShakeListener$OnShakeListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/platypus/dicer/MainActivity;->setShakeListener()V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$0:Lcom/platypus/dicer/MainActivity;


# direct methods
.method constructor <init>(Lcom/platypus/dicer/MainActivity;)V
    .locals 0

    .prologue
    .line 97
    iput-object p1, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onShake()V
    .locals 9

    .prologue
    const v8, 0x7f02005b

    const v7, 0x7f02005a

    const v6, 0x7f020059

    const v5, 0x7f020058

    const v4, 0x7f020057

    .line 100
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    const v3, 0x7f0b003f

    invoke-virtual {v2, v3}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/ImageView;

    .line 101
    .local v0, "v":Landroid/widget/ImageView;
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    const v3, 0x7f0b0040

    invoke-virtual {v2, v3}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/ImageView;

    .line 103
    .local v1, "vtwo":Landroid/widget/ImageView;
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    iget-boolean v2, v2, Lcom/platypus/dicer/MainActivity;->onedie:Z

    if-eqz v2, :cond_0

    .line 105
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2}, Lcom/platypus/dicer/MainActivity;->rollDice()I

    move-result v2

    packed-switch v2, :pswitch_data_0

    .line 168
    :goto_0
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2}, Lcom/platypus/dicer/MainActivity;->playDieSound()V

    .line 169
    return-void

    .line 107
    :pswitch_0
    invoke-virtual {v0, v4}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 110
    :pswitch_1
    invoke-virtual {v0, v5}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 113
    :pswitch_2
    invoke-virtual {v0, v6}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 116
    :pswitch_3
    invoke-virtual {v0, v7}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 119
    :pswitch_4
    invoke-virtual {v0, v8}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 122
    :pswitch_5
    const v2, 0x7f02005c

    invoke-virtual {v0, v2}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 126
    :cond_0
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2}, Lcom/platypus/dicer/MainActivity;->rollDice()I

    move-result v2

    packed-switch v2, :pswitch_data_1

    .line 146
    :goto_1
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2}, Lcom/platypus/dicer/MainActivity;->rollDice()I

    move-result v2

    packed-switch v2, :pswitch_data_2

    .line 166
    :goto_2
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity$1;->this$0:Lcom/platypus/dicer/MainActivity;

    invoke-virtual {v2}, Lcom/platypus/dicer/MainActivity;->playDieSound()V

    goto :goto_0

    .line 128
    :pswitch_6
    invoke-virtual {v1, v4}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_1

    .line 131
    :pswitch_7
    invoke-virtual {v1, v5}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_1

    .line 134
    :pswitch_8
    invoke-virtual {v1, v6}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_1

    .line 137
    :pswitch_9
    invoke-virtual {v1, v7}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_1

    .line 140
    :pswitch_a
    invoke-virtual {v1, v8}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_1

    .line 143
    :pswitch_b
    const v2, 0x7f02005c

    invoke-virtual {v1, v2}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_1

    .line 148
    :pswitch_c
    invoke-virtual {v0, v4}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_2

    .line 151
    :pswitch_d
    invoke-virtual {v0, v5}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_2

    .line 154
    :pswitch_e
    invoke-virtual {v0, v6}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_2

    .line 157
    :pswitch_f
    invoke-virtual {v0, v7}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_2

    .line 160
    :pswitch_10
    invoke-virtual {v0, v8}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_2

    .line 163
    :pswitch_11
    const v2, 0x7f02005c

    invoke-virtual {v0, v2}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_2

    .line 105
    nop

    :pswitch_data_0
    .packed-switch 0x1
        :pswitch_0
        :pswitch_1
        :pswitch_2
        :pswitch_3
        :pswitch_4
        :pswitch_5
    .end packed-switch

    .line 126
    :pswitch_data_1
    .packed-switch 0x1
        :pswitch_6
        :pswitch_7
        :pswitch_8
        :pswitch_9
        :pswitch_a
        :pswitch_b
    .end packed-switch

    .line 146
    :pswitch_data_2
    .packed-switch 0x1
        :pswitch_c
        :pswitch_d
        :pswitch_e
        :pswitch_f
        :pswitch_10
        :pswitch_11
    .end packed-switch
.end method
