.class Lcom/platypus/dicer/SettingsActivity$1;
.super Ljava/lang/Object;
.source "SettingsActivity.java"

# interfaces
.implements Landroid/preference/Preference$OnPreferenceClickListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/platypus/dicer/SettingsActivity;->onCreate(Landroid/os/Bundle;)V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$0:Lcom/platypus/dicer/SettingsActivity;


# direct methods
.method constructor <init>(Lcom/platypus/dicer/SettingsActivity;)V
    .locals 0

    .prologue
    .line 36
    iput-object p1, p0, Lcom/platypus/dicer/SettingsActivity$1;->this$0:Lcom/platypus/dicer/SettingsActivity;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onPreferenceClick(Landroid/preference/Preference;)Z
    .locals 3
    .param p1, "preference"    # Landroid/preference/Preference;

    .prologue
    .line 39
    iget-object v0, p0, Lcom/platypus/dicer/SettingsActivity$1;->this$0:Lcom/platypus/dicer/SettingsActivity;

    iget-object v1, p0, Lcom/platypus/dicer/SettingsActivity$1;->this$0:Lcom/platypus/dicer/SettingsActivity;

    const v2, 0x7f0b0043

    invoke-virtual {v1, v2}, Lcom/platypus/dicer/SettingsActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    invoke-virtual {v0, v1}, Lcom/platypus/dicer/SettingsActivity;->openSettings(Landroid/view/View;)V

    .line 40
    const/4 v0, 0x1

    return v0
.end method
