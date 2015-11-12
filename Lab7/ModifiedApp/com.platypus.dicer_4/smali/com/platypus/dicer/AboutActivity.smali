.class public Lcom/platypus/dicer/AboutActivity;
.super Landroid/app/Activity;
.source "AboutActivity.java"


# direct methods
.method public constructor <init>()V
    .locals 0

    .prologue
    .line 30
    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 1
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .prologue
    .line 33
    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    .line 34
    const v0, 0x7f030018

    invoke-virtual {p0, v0}, Lcom/platypus/dicer/AboutActivity;->setContentView(I)V

    .line 35
    return-void
.end method

.method public onStart()V
    .locals 14

    .prologue
    const/4 v13, 0x1

    const/4 v12, 0x0

    .line 38
    invoke-super {p0}, Landroid/app/Activity;->onStart()V

    .line 40
    invoke-virtual {p0}, Lcom/platypus/dicer/AboutActivity;->getResources()Landroid/content/res/Resources;

    move-result-object v5

    .line 44
    .local v5, "res":Landroid/content/res/Resources;
    :try_start_0
    invoke-virtual {p0}, Lcom/platypus/dicer/AboutActivity;->getPackageManager()Landroid/content/pm/PackageManager;

    move-result-object v4

    .line 45
    .local v4, "pm":Landroid/content/pm/PackageManager;
    invoke-virtual {p0}, Lcom/platypus/dicer/AboutActivity;->getPackageName()Ljava/lang/String;

    move-result-object v8

    const/4 v9, 0x0

    invoke-virtual {v4, v8, v9}, Landroid/content/pm/PackageManager;->getPackageInfo(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;

    move-result-object v1

    .line 46
    .local v1, "info":Landroid/content/pm/PackageInfo;
    const v8, 0x7f0d0010

    const/4 v9, 0x2

    new-array v9, v9, [Ljava/lang/Object;

    const/4 v10, 0x0

    iget-object v11, v1, Landroid/content/pm/PackageInfo;->versionName:Ljava/lang/String;

    aput-object v11, v9, v10

    const/4 v10, 0x1

    iget v11, v1, Landroid/content/pm/PackageInfo;->versionCode:I

    invoke-static {v11}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v11

    aput-object v11, v9, v10

    invoke-virtual {v5, v8, v9}, Landroid/content/res/Resources;->getString(I[Ljava/lang/Object;)Ljava/lang/String;

    move-result-object v7

    .line 47
    .local v7, "v":Ljava/lang/String;
    const v8, 0x7f0b003c

    invoke-virtual {p0, v8}, Lcom/platypus/dicer/AboutActivity;->findViewById(I)Landroid/view/View;

    move-result-object v6

    check-cast v6, Landroid/widget/TextView;

    .line 48
    .local v6, "tv":Landroid/widget/TextView;
    invoke-virtual {v6, v7}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V
    :try_end_0
    .catch Landroid/content/pm/PackageManager$NameNotFoundException; {:try_start_0 .. :try_end_0} :catch_0

    .line 53
    .end local v1    # "info":Landroid/content/pm/PackageInfo;
    .end local v4    # "pm":Landroid/content/pm/PackageManager;
    .end local v6    # "tv":Landroid/widget/TextView;
    .end local v7    # "v":Ljava/lang/String;
    :goto_0
    const v8, 0x7f0b003d

    invoke-virtual {p0, v8}, Lcom/platypus/dicer/AboutActivity;->findViewById(I)Landroid/view/View;

    move-result-object v6

    check-cast v6, Landroid/widget/TextView;

    .line 54
    .restart local v6    # "tv":Landroid/widget/TextView;
    const v8, 0x7f0d000d

    invoke-virtual {v6, v8}, Landroid/widget/TextView;->setText(I)V

    .line 56
    const v8, 0x7f0d000e

    invoke-virtual {v5, v8}, Landroid/content/res/Resources;->getString(I)Ljava/lang/String;

    move-result-object v2

    .line 57
    .local v2, "link":Ljava/lang/String;
    const v8, 0x7f0d000f

    new-array v9, v13, [Ljava/lang/Object;

    aput-object v2, v9, v12

    invoke-virtual {v5, v8, v9}, Landroid/content/res/Resources;->getString(I[Ljava/lang/Object;)Ljava/lang/String;

    move-result-object v3

    .line 58
    .local v3, "linktext":Ljava/lang/String;
    const v8, 0x7f0b003e

    invoke-virtual {p0, v8}, Lcom/platypus/dicer/AboutActivity;->findViewById(I)Landroid/view/View;

    move-result-object v6

    .end local v6    # "tv":Landroid/widget/TextView;
    check-cast v6, Landroid/widget/TextView;

    .line 59
    .restart local v6    # "tv":Landroid/widget/TextView;
    invoke-static {}, Landroid/text/method/LinkMovementMethod;->getInstance()Landroid/text/method/MovementMethod;

    move-result-object v8

    invoke-virtual {v6, v8}, Landroid/widget/TextView;->setMovementMethod(Landroid/text/method/MovementMethod;)V

    .line 60
    invoke-static {v3}, Landroid/text/Html;->fromHtml(Ljava/lang/String;)Landroid/text/Spanned;

    move-result-object v8

    invoke-virtual {v6, v8}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 61
    return-void

    .line 49
    .end local v2    # "link":Ljava/lang/String;
    .end local v3    # "linktext":Ljava/lang/String;
    .end local v6    # "tv":Landroid/widget/TextView;
    :catch_0
    move-exception v0

    .line 50
    .local v0, "e":Landroid/content/pm/PackageManager$NameNotFoundException;
    invoke-virtual {v0}, Landroid/content/pm/PackageManager$NameNotFoundException;->printStackTrace()V

    goto :goto_0
.end method
