# SELECT : ����

    MAX(�÷���) ������ �ִ밪 (DATETIME TYPE�� ����)
    MIN(�÷���) ������ �ּҰ� (DATETIME TYPE�� ����)
    SUM(�÷���) ���� �ִ� ���� ��
    AVG(�÷���) ���� �ִ� ���� ���
    COUNT(�÷���) �ش� ���� ����ִ� ���� �� & NULL ������ ��
    COUNT(\*) ��� ���ڵ� �� & NULL ������ ��
    COUNT(DISTINCT �÷���) ���� �ߺ��Ǵ� ���� �� ���� ī��Ʈ�� ��
    DISTINCT �÷��� / DISTINCT(�÷���)
    HOUR(�÷���) �÷��� DATETIME�϶�, 9:45��, 9:58�� 9�� ������
    IFNULL(�÷���, 0) �ش� �÷��� ���� ������ �ΰ��� 0���� �ٲ㼭 ����
    IF(����, ��, ����) ������ ������ �� ����, Ʋ���� ���� ����
    CASE ���̽� ���� ǥ��
        WHEN ~~ THEN 'A' // ~~�̸� A ����
        WHEN ~~~ THEN 'B' // ~~~�̸� B ��ö
        ELSE 'C' // �� �ƴϸ� C ����
    END ���̽� ���� ǥ��
    BETWEEN A AND B
    DATEDIFF(A, B) A�Ⱓ - B�Ⱓ : ��¥ ���̰� (�� A.DATETIME-B.DATETIME�� ��)
    DATE_FORMAT(DATETIME, '%Y-%m-%d') ����Ͻú��ʸ� ����Ϸ� �ٲٱ�

# WHERE : ���� �˻��Ҷ�

    = ������
    != �ٸ���
    IS NULL �� �ΰ�
    IS NOT NULL �� �ƴѰ�
    (BINARY) LIKE "%�ٺ�%" �ٺ��� ���ԵȰ�, BINARY������ ��ҹ��� ����X
    �÷��� IN ("~~~", "~~", "~", "~~~~") �÷��ȿ� ��ȣ �� ���� ���°͸�

# ORDER BY : ������� ����

    ASC, ���� ��������,
    DESC ��������

# LIMIT : ���ڸ�ŭ�� SELECT��

    LIMIT 1 ���� ������ �ϳ��� ���

# GROUP BY : ���� ���� ���� �ֵ��� �ϳ��� �׷����� ���

# HAVING : GROUP BY ����� ���Ǵޱ�

    (EX; SELECT�� WHERE ����), �����Լ�(MAX, MIN, SUM, AVG ��)����ؾ���

# UNION : ���� �ٸ� ���̺��� ���ļ� �� ����..(?)

# JOIN ========================================

    \*LEFT JOIN : A�� + A��B ��ģ �� (- B��)
    SELECT
    FROM TABLEA A
    LEFT JOIN TALEEB B
    ON A.KEY = B.KEY
    (WHERE B.KEY IS NULL) : A�� - A��B ��ģ �� (- B��)

    \*INNER JOIN : A��B ��ģ ��
    SELECT
    FROM TABLEA A
    INNER JOIN TABLE B
    ON A.KEY=B.KEY
