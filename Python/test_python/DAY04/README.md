# DAY 04 – Исключения, работа с сетью
## Классы, наследование, атрибуты классов и объектов
В рамках этого дня вы изучите исключения и работу с сетью в Python.

## Оглавление

1. [Глава I](#глава-i) \
    1.1. [Преамбула](#преамбула)
2. [Глава II](#глава-ii) \
    2.1. [Общая инструкция](#общая-инструкция)
3. [Глава III](#глава-iii) \
    3.1. [Цели](#цели)
4. [Глава IV](#глава-iv) \
    4.1. [Задание](#задание)
5. [Глава V](#глава-v) \
    5.1. [Сдача работы и проверка](#сдача-работы-и-проверка)

## Глава I
### Преамбула

Важная часть любого языка программирования высокого уровня - это исключения и способы обработки ошибок. Ошибки могут возникнуть всегда, и при этом не всегда по вине программиста. Например, при подключении к базе данных отключилась сеть или произошла ошибка записи в базу по каким-то ее внутренним причинам. Наше приложение должно уметь обрабатывать такие ситуации, поэтому мы должны научиться использовать исключения в нашем коде. Вторая тема, рассмотренная в этом уроке, это работа с сетью со стороны клиента. В рамках курса по разработке веб-приложений на питоне мы вообще-то будем писать бэкенд, т.е. логику, которая исполняется на сервере. Но также нам полезно понимать и то, как процесс передачи-получения данных устроен и с другой стороны - со стороны клиента.

## Глава II
### Общая инструкция

Методология Школы 21 может быть не похожа на тот образовательный опыт, который с вами случался ранее. Ее отличает высокий уровень автономии: у вас есть задача, вы должны ее выполнить. По большей части вам нужно будет самим добывать знания для ее решения. Второй важный момент – это peer-to-peer обучение. В образовательном процессе нет преподавателей и экспертов, перед которыми вы защищаете свой результат. Вы это делаете перед таким же учащимися, как и вы сами. У них есть чек-лист, который поможет им выполнить приемку вашей работы качественно.

Роль Школы 21 заключается в том, чтобы обеспечить через последовательность заданий и оптимальный уровень поддержки такую траекторию обучения, при которой вы освоите не только hard skills, но и научитесь самообучаться.

* Не доверяйте слухам и предположениям о том, как должно быть оформлено ваше решение. Этот документ является единственным источником, к которому стоит обращаться по большинству вопросов.
* Ваше решение будет оцениваться другими учащимися бассейна.
* Подлежат оцениванию только те файлы, которые вы выложили в GIT.
* В вашей папке не должно быть лишних файлов – только те, что были указаны в задании.
* Есть вопрос? Спросите коллегу справа. Не помогло? Спросите коллегу слева.
* Не забывайте, что у вас есть доступ к интернету и поисковым системам.
* Обсуждение заданий можно вести и в Slack бассейна.
* Будьте внимательные к примерам, указанным в этом документе – они могут иметь важные детали, которые не были оговорены другим способом.
* И да пребудет с вами Сила!

Примечание. В папке src хранятся блокноты с конспектами и заданиями. В некоторых из них используются картинки, и чтобы они отображались, в той же папке лежат папки с ними, которые вам нет необходимости просматривать.

## Глава III
### Цели

Наша цель - освоить работу с исключениями и сетью в питоне.

## Глава IV
### Задание

В этом дне вас ждут 2 задачи, в одной из которых нужно будет описать вызовы и обработку исключений, а в другой - составить несколько запросов к удаленному серверу и отправить ответ на другой удаленный сервер. Как и в предыдущих днях, эти задачи можно проверить автоматически в Яндекс.Контесте по ссылке https://contest.yandex.ru/contest/40435/enter/

Что нужно сделать:
1. Напишите скрипт, решающий задачу, описанную по адресу https://contest.yandex.ru/contest/40435/problems/16/.
2. Напишите скрипт, решающий задачу, описанную по адресу https://contest.yandex.ru/contest/40435/problems/17/.


Все решения должны проходить соответствующие тесты из Яндекс.Контеста. Соответствие задач из контеста задачам из задания приведено в блокнотах с конспектами.

## Глава V
### Сдача работы и проверка

Вам нужно загрузить в GIT в папку `src` свой Jupyter Notebook, в котором заполнены ячейки, предусмотренные для решения заданий.