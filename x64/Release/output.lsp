;// ����������� ��������� ������ ������ � ��������� ����� � ������
;// ��������� ��������� ������ ������ � ��������� ����� � �����
(defun C:F_Blockinsert(/ x1 x2 x3)
 (setq actdoc(vla-get-ActiveDocument(vlax-get-acad-object)))
	(setq obj(vla-get-ModelSpace actdoc))
(setq x1 1); ��������� �������� ������ ����� ����, ����� ��� ����������� �� ������� � �������� ������
(setq x2 1); �� ������� ����� ����������� ���������� ����� �������� ������
; ���������� ������� ��������� ������� ORTHO, SNAP � OSNAP
(setq old_ortho(getvar "ORTHOMODE")
old_snap(getvar "SNAPMODE")
old_osnap(getvar "OSMODE")
	)
	; ��������� ������ ORTHO, SNAP � OSNAP
(princ "Input : F_Blockinsert "); ������������ ����� ���������� � ������� �++, ������� �������� � �������� ���, ���� ���
(setvar "ORTHOMODE" 0); � ����� ����� ��������� ������������
(setvar "SNAPMODE" 0)
(setvar "OSMODE" 0)
