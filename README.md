# My custom keymap for Ergodex EZ

### ファームウェア本体
https://github.com/qmk/qmk_firmware

以下の場所にこのリポジトリを取り込む
```
keyboards/ergodox_ez/keymaps
```

### ビルド環境
https://docs.qmk.fm/install-build-tools#linux

### ビルド

ファームウェア本体のトップレベルで make
```
make ergodox_ez:my_ergodox_keymap
成功すると .build/ 以下に hex ファイルができる
```

https://docs.qmk.fm/build-compile-instructions

### 書き込み

https://www.pjrc.com/teensy/loader.html
