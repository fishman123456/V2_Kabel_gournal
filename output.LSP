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
(command "_.-layer" "_m" "-B31.150.1-S1	" "") (vla-InsertBlock obj(vlax-3D-point '(122000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.150.1-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(124000 2000 0))  "Terminal_box" 1 1 1 0)
(command "_.-layer" "_m" "-B31.150.1-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(126000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.150.2-S1	" "") (vla-InsertBlock obj(vlax-3D-point '(128000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.150.2-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(130000 2000 0))  "Terminal_box" 1 1 1 0)
(command "_.-layer" "_m" "-B31.150.2-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(132000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.65.1-S1	" "") (vla-InsertBlock obj(vlax-3D-point '(134000 2000 0))  "Terminal_box" 1 1 1 0)
(command "_.-layer" "_m" "-B31.65.1-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(136000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.65.1-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(138000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.65.2-S1	" "") (vla-InsertBlock obj(vlax-3D-point '(140000 2000 0))  "Terminal_box" 1 1 1 0)
(command "_.-layer" "_m" "-B31.65.2-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(142000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.65.2-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(144000 2000 0))  "electric_motor" 1 1 1 0)
(command "_.-layer" "_m" "-B31.65.2-K2	" "") (vla-InsertBlock obj(vlax-3D-point '(144000 2000 0))  "electric_motor" 1 1 1 0)
(alert "Закончили")
)
