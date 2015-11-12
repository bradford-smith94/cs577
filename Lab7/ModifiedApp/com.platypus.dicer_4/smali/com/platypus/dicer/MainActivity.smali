.class public Lcom/platypus/dicer/MainActivity;
.super Landroid/app/Activity;
.source "MainActivity.java"

# interfaces
.implements Landroid/content/SharedPreferences$OnSharedPreferenceChangeListener;


# static fields
.field public static final PREFS:Ljava/lang/String; = "PrefsFile"


# instance fields
.field protected onedie:Z

.field protected shaketoroll:Z

.field private shali:Lcom/platypus/dicer/ShakeListener;

.field protected showDice:Z

.field protected vibrate:Z


# direct methods
.method public constructor <init>()V
    .locals 2

    .prologue
    const/4 v1, 0x1

    .line 39
    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    .line 41
    const/4 v0, 0x0

    iput-boolean v0, p0, Lcom/platypus/dicer/MainActivity;->onedie:Z

    .line 42
    iput-boolean v1, p0, Lcom/platypus/dicer/MainActivity;->shaketoroll:Z

    .line 43
    iput-boolean v1, p0, Lcom/platypus/dicer/MainActivity;->vibrate:Z

    .line 45
    iput-boolean v1, p0, Lcom/platypus/dicer/MainActivity;->showDice:Z

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 5
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .prologue
    const/4 v4, 0x1

    .line 51
    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    .line 54
    const-string v2, "PrefsFile"

    const/4 v3, 0x0

    invoke-virtual {p0, v2, v3}, Lcom/platypus/dicer/MainActivity;->getSharedPreferences(Ljava/lang/String;I)Landroid/content/SharedPreferences;

    move-result-object v0

    .line 55
    .local v0, "settings":Landroid/content/SharedPreferences;
    const-string v2, "onedie"

    invoke-interface {v0, v2, v4}, Landroid/content/SharedPreferences;->getBoolean(Ljava/lang/String;Z)Z

    move-result v2

    iput-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->onedie:Z

    .line 56
    const-string v2, "shake"

    invoke-interface {v0, v2, v4}, Landroid/content/SharedPreferences;->getBoolean(Ljava/lang/String;Z)Z

    move-result v2

    iput-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->shaketoroll:Z

    .line 57
    const-string v2, "vibrate"

    invoke-interface {v0, v2, v4}, Landroid/content/SharedPreferences;->getBoolean(Ljava/lang/String;Z)Z

    move-result v2

    iput-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->vibrate:Z

    .line 60
    invoke-static {p0}, Landroid/preference/PreferenceManager;->getDefaultSharedPreferences(Landroid/content/Context;)Landroid/content/SharedPreferences;

    move-result-object v1

    .line 61
    .local v1, "sp":Landroid/content/SharedPreferences;
    invoke-interface {v1, p0}, Landroid/content/SharedPreferences;->registerOnSharedPreferenceChangeListener(Landroid/content/SharedPreferences$OnSharedPreferenceChangeListener;)V

    .line 64
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->setLayout()V

    .line 67
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->setImageListeners()V

    .line 70
    iget-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->shaketoroll:Z

    if-nez v2, :cond_0

    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->setShakeListener()V

    .line 71
    :cond_0
    return-void
.end method

.method public onCreateOptionsMenu(Landroid/view/Menu;)Z
    .locals 2
    .param p1, "menu"    # Landroid/view/Menu;

    .prologue
    .line 315
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->getMenuInflater()Landroid/view/MenuInflater;

    move-result-object v0

    .line 316
    .local v0, "mf":Landroid/view/MenuInflater;
    const/high16 v1, 0x7f0f0000

    invoke-virtual {v0, v1, p1}, Landroid/view/MenuInflater;->inflate(ILandroid/view/Menu;)V

    .line 317
    invoke-super {p0, p1}, Landroid/app/Activity;->onCreateOptionsMenu(Landroid/view/Menu;)Z

    move-result v1

    return v1
.end method

.method public onOptionsItemSelected(Landroid/view/MenuItem;)Z
    .locals 2
    .param p1, "item"    # Landroid/view/MenuItem;

    .prologue
    const/4 v0, 0x1

    .line 325
    invoke-interface {p1}, Landroid/view/MenuItem;->getItemId()I

    move-result v1

    packed-switch v1, :pswitch_data_0

    .line 333
    invoke-super {p0, p1}, Landroid/app/Activity;->onOptionsItemSelected(Landroid/view/MenuItem;)Z

    move-result v0

    :goto_0
    return v0

    .line 327
    :pswitch_0
    const v1, 0x7f0b0043

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/MainActivity;->openSettings(Landroid/view/View;)V

    goto :goto_0

    .line 330
    :pswitch_1
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->finish()V

    goto :goto_0

    .line 325
    :pswitch_data_0
    .packed-switch 0x7f0b0043
        :pswitch_0
        :pswitch_1
    .end packed-switch
.end method

.method protected onResume()V
    .locals 0

    .prologue
    .line 89
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->setLayout()V

    .line 90
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->setShakeListener()V

    .line 91
    invoke-super {p0}, Landroid/app/Activity;->onResume()V

    .line 92
    return-void
.end method

.method public onSharedPreferenceChanged(Landroid/content/SharedPreferences;Ljava/lang/String;)V
    .locals 4
    .param p1, "sharedPreferences"    # Landroid/content/SharedPreferences;
    .param p2, "s"    # Ljava/lang/String;

    .prologue
    .line 342
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->getBaseContext()Landroid/content/Context;

    move-result-object v2

    invoke-static {v2}, Landroid/preference/PreferenceManager;->getDefaultSharedPreferences(Landroid/content/Context;)Landroid/content/SharedPreferences;

    move-result-object v0

    .line 343
    .local v0, "sp":Landroid/content/SharedPreferences;
    const-string v2, "PREF_NUMBEROFDIES"

    const-string v3, "none"

    invoke-interface {v0, v2, v3}, Landroid/content/SharedPreferences;->getString(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    .line 344
    .local v1, "string":Ljava/lang/String;
    const-string v2, "1"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    iput-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->onedie:Z

    .line 345
    const-string v2, "PREF_SHAKETOROLL"

    const/4 v3, 0x0

    invoke-interface {v0, v2, v3}, Landroid/content/SharedPreferences;->getBoolean(Ljava/lang/String;Z)Z

    move-result v2

    iput-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->shaketoroll:Z

    .line 346
    const-string v2, "PREF_VIBRATE"

    const/4 v3, 0x1

    invoke-interface {v0, v2, v3}, Landroid/content/SharedPreferences;->getBoolean(Ljava/lang/String;Z)Z

    move-result v2

    iput-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->vibrate:Z

    .line 348
    return-void
.end method

.method protected onStop()V
    .locals 4

    .prologue
    .line 74
    iget-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->shaketoroll:Z

    if-eqz v2, :cond_0

    .line 75
    iget-object v2, p0, Lcom/platypus/dicer/MainActivity;->shali:Lcom/platypus/dicer/ShakeListener;

    invoke-virtual {v2}, Lcom/platypus/dicer/ShakeListener;->pause()V

    .line 77
    :cond_0
    invoke-super {p0}, Landroid/app/Activity;->onStop()V

    .line 79
    const-string v2, "PrefsFile"

    const/4 v3, 0x0

    invoke-virtual {p0, v2, v3}, Lcom/platypus/dicer/MainActivity;->getSharedPreferences(Ljava/lang/String;I)Landroid/content/SharedPreferences;

    move-result-object v1

    .line 80
    .local v1, "settings":Landroid/content/SharedPreferences;
    invoke-interface {v1}, Landroid/content/SharedPreferences;->edit()Landroid/content/SharedPreferences$Editor;

    move-result-object v0

    .line 81
    .local v0, "editor":Landroid/content/SharedPreferences$Editor;
    const-string v2, "onedie"

    iget-boolean v3, p0, Lcom/platypus/dicer/MainActivity;->onedie:Z

    invoke-interface {v0, v2, v3}, Landroid/content/SharedPreferences$Editor;->putBoolean(Ljava/lang/String;Z)Landroid/content/SharedPreferences$Editor;

    .line 82
    const-string v2, "shake"

    iget-boolean v3, p0, Lcom/platypus/dicer/MainActivity;->shaketoroll:Z

    invoke-interface {v0, v2, v3}, Landroid/content/SharedPreferences$Editor;->putBoolean(Ljava/lang/String;Z)Landroid/content/SharedPreferences$Editor;

    .line 83
    const-string v2, "vibrate"

    iget-boolean v3, p0, Lcom/platypus/dicer/MainActivity;->vibrate:Z

    invoke-interface {v0, v2, v3}, Landroid/content/SharedPreferences$Editor;->putBoolean(Ljava/lang/String;Z)Landroid/content/SharedPreferences$Editor;

    .line 84
    invoke-interface {v0}, Landroid/content/SharedPreferences$Editor;->commit()Z

    .line 85
    return-void
.end method

.method public openSettings(Landroid/view/View;)V
    .locals 2
    .param p1, "view"    # Landroid/view/View;

    .prologue
    .line 337
    new-instance v0, Landroid/content/Intent;

    const-class v1, Lcom/platypus/dicer/SettingsActivity;

    invoke-direct {v0, p0, v1}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    .line 338
    .local v0, "intent":Landroid/content/Intent;
    invoke-virtual {p0, v0}, Lcom/platypus/dicer/MainActivity;->startActivity(Landroid/content/Intent;)V

    .line 339
    return-void
.end method

.method protected playDieSound()V
    .locals 9

    .prologue
    const/high16 v8, 0x7f060000

    const/4 v4, 0x0

    const/high16 v2, 0x3f800000    # 1.0f

    .line 176
    new-instance v0, Landroid/media/SoundPool;

    const/4 v3, 0x5

    const/4 v5, 0x3

    invoke-direct {v0, v3, v5, v4}, Landroid/media/SoundPool;-><init>(III)V

    .line 177
    .local v0, "sp":Landroid/media/SoundPool;
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->getApplicationContext()Landroid/content/Context;

    move-result-object v3

    const/4 v5, 0x1

    invoke-virtual {v0, v3, v8, v5}, Landroid/media/SoundPool;->load(Landroid/content/Context;II)I

    move-result v1

    .local v1, "soundId":I
    move v3, v2

    move v5, v4

    move v6, v2

    .line 179
    invoke-virtual/range {v0 .. v6}, Landroid/media/SoundPool;->play(IFFIIF)I

    .line 181
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->getApplicationContext()Landroid/content/Context;

    move-result-object v2

    invoke-static {v2, v8}, Landroid/media/MediaPlayer;->create(Landroid/content/Context;I)Landroid/media/MediaPlayer;

    move-result-object v7

    .line 182
    .local v7, "mPlayer":Landroid/media/MediaPlayer;
    invoke-virtual {v7}, Landroid/media/MediaPlayer;->start()V

    .line 184
    return-void
.end method

.method protected rollDice()I
    .locals 4

    .prologue
    .line 310
    invoke-static {}, Ljava/lang/Math;->random()D

    move-result-wide v0

    const-wide/high16 v2, 0x4018000000000000L    # 6.0

    mul-double/2addr v0, v2

    const-wide/high16 v2, 0x3ff0000000000000L    # 1.0

    add-double/2addr v0, v2

    #added for Lab7 -- always return 6
    const-wide/high16 v0, 0x4018000000000000L

    double-to-int v0, v0

    return v0
.end method

.method protected setImageListeners()V
    .locals 3

    .prologue
    .line 244
    const v2, 0x7f0b003f

    invoke-virtual {p0, v2}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/ImageView;

    .line 245
    .local v0, "v":Landroid/widget/ImageView;
    const v2, 0x7f0b0040

    invoke-virtual {p0, v2}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/ImageView;

    .line 247
    .local v1, "vtwo":Landroid/widget/ImageView;
    iget-boolean v2, p0, Lcom/platypus/dicer/MainActivity;->onedie:Z

    if-eqz v2, :cond_0

    .line 248
    new-instance v2, Lcom/platypus/dicer/MainActivity$3;

    invoke-direct {v2, p0, v0}, Lcom/platypus/dicer/MainActivity$3;-><init>(Lcom/platypus/dicer/MainActivity;Landroid/widget/ImageView;)V

    invoke-virtual {v0, v2}, Landroid/widget/ImageView;->setOnTouchListener(Landroid/view/View$OnTouchListener;)V

    .line 283
    :goto_0
    return-void

    .line 259
    :cond_0
    new-instance v2, Lcom/platypus/dicer/MainActivity$4;

    invoke-direct {v2, p0, v1, v0}, Lcom/platypus/dicer/MainActivity$4;-><init>(Lcom/platypus/dicer/MainActivity;Landroid/widget/ImageView;Landroid/widget/ImageView;)V

    invoke-virtual {v0, v2}, Landroid/widget/ImageView;->setOnTouchListener(Landroid/view/View$OnTouchListener;)V

    .line 271
    new-instance v2, Lcom/platypus/dicer/MainActivity$5;

    invoke-direct {v2, p0, v1, v0}, Lcom/platypus/dicer/MainActivity$5;-><init>(Lcom/platypus/dicer/MainActivity;Landroid/widget/ImageView;Landroid/widget/ImageView;)V

    invoke-virtual {v1, v2}, Landroid/widget/ImageView;->setOnTouchListener(Landroid/view/View$OnTouchListener;)V

    goto :goto_0
.end method

.method public setLayout()V
    .locals 2

    .prologue
    .line 194
    iget-boolean v1, p0, Lcom/platypus/dicer/MainActivity;->onedie:Z

    if-eqz v1, :cond_0

    .line 195
    const v1, 0x7f030019

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/MainActivity;->setContentView(I)V

    .line 241
    :goto_0
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->setImageListeners()V

    .line 242
    return-void

    .line 198
    :cond_0
    const v1, 0x7f03001a

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/MainActivity;->setContentView(I)V

    .line 199
    const v1, 0x7f0b0041

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/Button;

    .line 200
    .local v0, "button":Landroid/widget/Button;
    new-instance v1, Lcom/platypus/dicer/MainActivity$2;

    invoke-direct {v1, p0, v0}, Lcom/platypus/dicer/MainActivity$2;-><init>(Lcom/platypus/dicer/MainActivity;Landroid/widget/Button;)V

    invoke-virtual {v0, v1}, Landroid/widget/Button;->setOnClickListener(Landroid/view/View$OnClickListener;)V

    goto :goto_0
.end method

.method protected setShakeListener()V
    .locals 2

    .prologue
    .line 95
    iget-boolean v0, p0, Lcom/platypus/dicer/MainActivity;->shaketoroll:Z

    if-eqz v0, :cond_0

    .line 96
    new-instance v0, Lcom/platypus/dicer/ShakeListener;

    invoke-direct {v0, p0}, Lcom/platypus/dicer/ShakeListener;-><init>(Landroid/content/Context;)V

    iput-object v0, p0, Lcom/platypus/dicer/MainActivity;->shali:Lcom/platypus/dicer/ShakeListener;

    .line 97
    iget-object v0, p0, Lcom/platypus/dicer/MainActivity;->shali:Lcom/platypus/dicer/ShakeListener;

    new-instance v1, Lcom/platypus/dicer/MainActivity$1;

    invoke-direct {v1, p0}, Lcom/platypus/dicer/MainActivity$1;-><init>(Lcom/platypus/dicer/MainActivity;)V

    invoke-virtual {v0, v1}, Lcom/platypus/dicer/ShakeListener;->setOnShakeListener(Lcom/platypus/dicer/ShakeListener$OnShakeListener;)V

    .line 173
    :cond_0
    return-void
.end method

.method protected shuffleImage(Landroid/widget/ImageView;)V
    .locals 1
    .param p1, "v"    # Landroid/widget/ImageView;

    .prologue
    .line 286
    invoke-virtual {p0}, Lcom/platypus/dicer/MainActivity;->rollDice()I

    move-result v0

    packed-switch v0, :pswitch_data_0

    .line 306
    :goto_0
    return-void

    .line 288
    :pswitch_0
    const v0, 0x7f020057

    invoke-virtual {p1, v0}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 291
    :pswitch_1
    const v0, 0x7f020058

    invoke-virtual {p1, v0}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 294
    :pswitch_2
    const v0, 0x7f020059

    invoke-virtual {p1, v0}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 297
    :pswitch_3
    const v0, 0x7f02005a

    invoke-virtual {p1, v0}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 300
    :pswitch_4
    const v0, 0x7f02005b

    invoke-virtual {p1, v0}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 303
    :pswitch_5
    const v0, 0x7f02005c

    invoke-virtual {p1, v0}, Landroid/widget/ImageView;->setImageResource(I)V

    goto :goto_0

    .line 286
    :pswitch_data_0
    .packed-switch 0x1
        :pswitch_0
        :pswitch_1
        :pswitch_2
        :pswitch_3
        :pswitch_4
        :pswitch_5
    .end packed-switch
.end method

.method protected vibrate()V
    .locals 4

    .prologue
    .line 187
    iget-boolean v1, p0, Lcom/platypus/dicer/MainActivity;->vibrate:Z

    if-eqz v1, :cond_0

    .line 188
    const-string v1, "vibrator"

    invoke-virtual {p0, v1}, Lcom/platypus/dicer/MainActivity;->getSystemService(Ljava/lang/String;)Ljava/lang/Object;

    move-result-object v0

    check-cast v0, Landroid/os/Vibrator;

    .line 189
    .local v0, "vibrator":Landroid/os/Vibrator;
    const-wide/16 v2, 0x46

    invoke-virtual {v0, v2, v3}, Landroid/os/Vibrator;->vibrate(J)V

    .line 191
    .end local v0    # "vibrator":Landroid/os/Vibrator;
    :cond_0
    return-void
.end method
