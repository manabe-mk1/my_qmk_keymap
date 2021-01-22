# My custom keymap for qmk

### ファームウェア本体

https://github.com/qmk/qmk_firmware

### ビルド環境構築

python 3.6 以上が必要

```
sudo apt install git python3-pip
python3 -m pip install --user qmk
```

セットアップコマンドを実行するとホームディレクトリ直下にファームウェアのリポジトリが
clone されるので、リポジトリ内の以下の場所にこのリポジトリを取り込む

```
qmk setup
ls ~/qmk_firmware
cd keyboards/<keyboard>/keymaps
git clone git@github.com:manabe-mk1/my_qmk_keymap.git
```

https://docs.qmk.fm/#/newbs_getting_started?id=linux

### ビルド

```
qmk compile -kb <keyboard> -km my_qmk_keymap
```

成功すると ~/qmk_firmware/.build/ 以下に hex ファイルができる

### 書き込み

https://www.pjrc.com/teensy/loader.html
