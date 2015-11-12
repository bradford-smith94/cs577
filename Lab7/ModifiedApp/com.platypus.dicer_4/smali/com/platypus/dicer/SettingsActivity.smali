.class public Lcom/platypus/dicer/SettingsActivity;
.super Landroid/preference/PreferenceActivity;
.source "SettingsActivity.java"


# direct methods
.method public constructor <init>()V
    .locals 0

    .prologue
    .line 29
    invoke-direct {p0}, Landroid/preference/PreferenceActivity;-><init>()V

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 2
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .prologue
    .line 32
    invoke-super {p0, p1}, Landroid/preference/PreferenceActivity;->onCreate(Landroid/os/Bundle;)V

    .line 34
    const/high16 v1, 0x7f050000

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/SettingsActivity;->addPreferencesFromResource(I)V

    .line 35
    const-string v1, "PREF_ABOUT"

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/SettingsActivity;->findPreference(Ljava/lang/CharSequence;)Landroid/preference/Preference;

    move-result-object v0

    .line 36
    .local v0, "myPref":Landroid/preference/Preference;
    new-instance v1, Lcom/platypus/dicer/SettingsActivity$1;

    invoke-direct {v1, p0}, Lcom/platypus/dicer/SettingsActivity$1;-><init>(Lcom/platypus/dicer/SettingsActivity;)V

    invoke-virtual {v0, v1}, Landroid/preference/Preference;->setOnPreferenceClickListener(Landroid/preference/Preference$OnPreferenceClickListener;)V

    .line 43
    return-void
.end method

.method public openSettings(Landroid/view/View;)V
    .locals 2
    .param p1, "view"    # Landroid/view/View;

    .prologue
    .line 46
    new-instance v0, Landroid/content/Intent;

    const-class v1, Lcom/platypus/dicer/AboutActivity;

    invoke-direct {v0, p0, v1}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    .line 47
    .local v0, "intent":Landroid/content/Intent;
    invoke-virtual {p0, v0}, Lcom/platypus/dicer/SettingsActivity;->startActivity(Landroid/content/Intent;)V

    .line 48
    return-void
.end method
