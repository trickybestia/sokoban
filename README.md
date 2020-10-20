# Сокобан
Легендарный сокобан, написанный на C++ с использованием фреймворка SFML.
![](https://raw.githubusercontent.com/TheWonderfulCookie/sokoban/master/Docs/Images/demo1.png)
### Управление
Перемещение персонажа происходит по нажатию W/A/S/D или по нажатию ↑/←/↓/→.
### Правила
Необходимо переместить все ящики так, чтобы над каждой целью (красный крестик) оказался ящик.
### Карты
###### Формат
По умолчанию в игре три карты, но можно создать и собственные.
Для создания карты нужно создать текстовый файл с расширением .map и записать в него текст в следующем формате (для записи можно пользоваться "Блокнотом" в Windows или другим текстовом редакторе):
```
ширина_карты высота_карты
*Символ каждой клетки*
```
###### Символы клеток
+ w (wall) - стена
+ f (floor) - пустая клетка (пол)
+ t (target) - цель для ящика
+ c (crate) - ящик
+ p (player) - игрок
На карте должен быть только один игрок!
###### Пример карты
Название - 4.map
Содержимое:
```
8 8
wwwwwwww
wwpfwwww
wwfcffww
wwwfwfww
wtwfwffw
wtcffwfw
wtfffcfw
wwwwwwww
```