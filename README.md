# BSQ
<h2>Данный проект был написан в период прохождения отбора в школу Сбербанка 21 в Москве. </h2>

◦ Цель этого проекта - найти самую большую площадь на карте, избегая препятствий.
Карта генерируется с помощью кода на perl и записывается в файл, который потом передается в качестве 
аргумента для этой программы.
![](https://github.com/Anastasiya1405/BSQ/raw/master/2.png) <br>
◦ Первая строка карты содержит информацию о том, как читать карту: <br>
1) Количество линий на карте; <br>
2) символ «пустоты»; <br>
3) символ «препятствия»; <br>
4) символ «заполненного» поля. <br>
«Карта состоит из «пустых» символов, линий и «препятствий». <br>

◦ Цель программы - заменить «пустые» символы на «полные» символы, чтобы представить максимально возможную площадь. <br>
◦ В случае, если существует более одного решения, мы выбираем представление квадрата, который находится ближе всего <br>
к вершине карты, а затем квадрата, который расположен левее всех. <br>

<h3>Ограничения: </h3><br>
 • Определение действительной карты: <br>
Все строки должны иметь одинаковую длину. <br>
◦ Есть хотя бы одна состоящая как минимум из одного символа. <br>
◦ На каждом конце строки есть разрыв строки. <br>
◦ Символы на карте могут быть только теми, которые введены в первой строке. <br>
◦ В случае неверной карты программа должна отобразить ошибку карты в выводе  <br>
с последующим переводом строки. И программа перейдет к обработке следующей карте. <br>

Связей со сторонними объектами нет. <br>

<h2>Тестирование программы: </h2> <br>
<h3> №1(в качестве аргумента передана одна валидная карта) </h3>

![](https://github.com/Anastasiya1405/BSQ/raw/master/1.png) 
<br> <br>
<h3> №2(в качестве аргумента передано несколько валидных карт) </h3>

![](https://github.com/Anastasiya1405/BSQ/raw/master/3.png) 
<br> 
![](https://github.com/Anastasiya1405/BSQ/raw/master/4.png) 
<br> <br>
<h3> №3(в качестве аргумента передана одна невалидная карта(количество строк меньше заявленных 9)) </h3>

![](https://github.com/Anastasiya1405/BSQ/raw/master/5.png)
 <br> <br>


