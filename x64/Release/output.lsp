;// ОБЯЗАТЕЛЬНО ОСТАВЛЯТЬ ПУСТУЮ СТРОКУ В ТЕКСТОВОМ ФАЙЛЕ В НАЧАЛЕ
;// ЗАПРЕЩЕНО ОСТАВЛЯТЬ ПУСТЫЕ СТРОКИ В ТЕКСТОВОМ ФАЙЛЕ В КОНЦЕ
(defun C:F_Blockinsert(/ x1 x2 x3)
 (setq actdoc(vla-get-ActiveDocument(vlax-get-acad-object)))
	(setq obj(vla-get-ModelSpace actdoc))
(setq x1 1); начальное значение списка равно нулю, потом его увеличиваем на еденицу и получаем список
(setq x2 1); на сколько будем увеличивать порядковый номер элемента списка
; Запоминаем текущее состояние режимов ORTHO, SNAP И OSNAP
(setq old_ortho(getvar "ORTHOMODE")
old_snap(getvar "SNAPMODE")
old_osnap(getvar "OSMODE")
	)
	; отключаем режимы ORTHO, SNAP И OSNAP
(princ "Input : F_Blockinsert "); формирование файла происходит с помощью С++, Спасибо обучению в Академми ШАГ, ныне ТОР
(setvar "ORTHOMODE" 0); и лично Бакун Александр Владимтрович
(setvar "SNAPMODE" 0)
(setvar "OSMODE" 0)
