# SELECT : 추출

    MAX(컬럼명) 열에서 최대값 (DATETIME TYPE도 가능)
    MIN(컬럼명) 열에서 최소값 (DATETIME TYPE도 가능)
    SUM(컬럼명) 열에 있는 값의 합
    AVG(컬럼명) 열에 있는 값의 평균
    COUNT(컬럼명) 해당 열에 들어있는 행의 수 & NULL 제외한 값
    COUNT(\*) 모든 레코드 수 & NULL 포함한 값
    COUNT(DISTINCT 컬럼명) 열에 중복되는 행의 수 빼고 카운트한 값
    DISTINCT 컬럼명 / DISTINCT(컬럼명)
    HOUR(컬럼명) 컬럼이 DATETIME일때, 9:45도, 9:58도 9로 추출함
    IFNULL(컬럼명, 0) 해당 컬럼에 널이 있으면 널값은 0으로 바꿔서 추출
    IF(조건, 참, 거짓) 조건이 맞으면 참 추출, 틀리면 거짓 추출
    CASE 케이스 시작 표시
        WHEN ~~ THEN 'A' // ~~이면 A 추출
        WHEN ~~~ THEN 'B' // ~~~이면 B 추철
        ELSE 'C' // 다 아니면 C 추출
    END 케이스 종료 표시
    BETWEEN A AND B
    DATEDIFF(A, B) A기간 - B기간 : 날짜 차이값 (걍 A.DATETIME-B.DATETIME도 됨)
    DATE_FORMAT(DATETIME, '%Y-%m-%d') 년월일시분초를 년월일로 바꾸기

# WHERE : 조건 검색할때

    = 같으면
    != 다르면
    IS NULL 널 인거
    IS NOT NULL 널 아닌거
    (BINARY) LIKE "%바보%" 바보가 포함된거, BINARY없으면 대소문자 구분X
    컬럼명 IN ("~~~", "~~", "~", "~~~~") 컬럼안에 괄호 안 값들 들어가는것만

# ORDER BY : 순서대로 정렬

    ASC, 공백 오름차순,
    DESC 내림차순

# LIMIT : 숫자만큼만 SELECT함

    LIMIT 1 가장 위에꺼 하나만 출력

# GROUP BY : 같은 값을 가진 애들을 하나의 그룹으로 취급

# HAVING : GROUP BY 결과에 조건달기

    (EX; SELECT의 WHERE 느낌), 집계함수(MAX, MIN, SUM, AVG 등)사용해야함

# UNION : 서로 다른 테이블을 합쳐서 값 추출..(?)

# JOIN ========================================

    \*LEFT JOIN : A● + A와B 겹친 곳 (- B○)
    SELECT
    FROM TABLEA A
    LEFT JOIN TALEEB B
    ON A.KEY = B.KEY
    (WHERE B.KEY IS NULL) : A● - A와B 겹친 곳 (- B○)

    \*INNER JOIN : A와B 겹친 곳
    SELECT
    FROM TABLEA A
    INNER JOIN TABLE B
    ON A.KEY=B.KEY
