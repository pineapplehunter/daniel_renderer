# Daniel Renderer
## 依存関係
 * SDL2

## コンパイルの仕方
`main.c`から使うと仮定すると
```bash
$ gcc daniel_renderer.c -c -o daniel_renderer.o
$ gcc daniel_renderer.o main.c -lSDL2 -o main
```

## API
### 関数
| code                                    | ドキュメント                                                         |
| --------------------------------------- | -------------------------------------------------------------------- |
| `init()`                                | ライブラリの初期化をします。                                         |
| `quit()`                                | ライブラリを終了します。                                             |
| `setColor(char r,char g,char b,char a)` | 0~255の範囲で色の指定ができる。                                      |
| `point(int x, int y)`                   | x,yの位置を`setColor`で決めた色で塗る                                |
| `clear()`                               | `setColor`で決めた色で画面を塗りつぶす。                             |
| `show((*)(void))`                       | レンダリングをする内容が入った関数を入れると毎フレームに描写をする。 |
### データ
| code            | ドキュメント       |
| --------------- | ------------------ |
| `screen.width`  | ディスプレイの幅   |
| `screen.height` | ディスプレイの高さ |