// Write a function that gets an array of ints of length n, such that each element is between 0 and 9, and sorts the array.
void sort_digits(int* ar, int n) {
    int count[10] = {0};

  for (int i = 0; i < n; i++) {
      count[ar[i]]++;
  }

  int index = 0;
  for (int i = 0; i < 10; i++) {
      for (int j = 0; j < count[i]; j++) {
          ar[index++] = i;
      }
  }
}

//Write a function that gets two strings and checks if one is the reverse of the other
bool is_reverse(const char* str1, const char* str2) {
  int str_length = strlen(str1);

  for(int i = 0; i < str_length; i++)
  {
    if(str1[i] != str2[str_length - i -1])
    {
      return false;
    }
  }
  return true;
}


//most frequent char in aray
char most_frequent_char(const char* str) {
  int freq[256] = {0};
  int len = strlen(str);
  char most_frequent = '\0';
  int max_freq = 0;

  for (int i = 0; i < len; i++) {
      freq[str[i]]++;
      if (freq[str[i]] > max_freq) {
          max_freq = freq[str[i]];
          most_frequent = str[i];
      }
  }

  for (int i = 0; i < len; i++) {
      if (freq[str[i]] == max_freq && str[i] != most_frequent) {
          return most_frequent;
      }
  }

  return most_frequent;
}


//concatonate strings in array
char* concat_all(const char* arr[], int n) {
  // Calculate the total length of the concatenated string
  int total_length = 0;
  for (int i = 0; i < n; i++) {
      total_length += strlen(arr[i]);
  }

  // Allocate memory on the heap for the concatenated string
  char* result = (char*)malloc(total_length + 1);

  // Concatenate all strings into the result string
  int index = 0;
  for (int i = 0; i < n; i++) {
      int length = strlen(arr[i]);
      strncpy(result + index, arr[i], length);
      index += length;
  }

  // Add null terminator to the end of the result string
  result[total_length] = '\0';

  return result;
}


//palindrome for int
bool is_palindrome(unsigned int n) {
    char s[20];
    sprintf(s, "%u", n);
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}


//change lower case vowels into stars
int vowels2asterisks(char* ar[], int n) {
  char vowels[] = "aeiou";
  int count = 0;
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < strlen(ar[i]); j++) {
          if (ar[i][j] >= 'a' && ar[i][j] <= 'z') {
              for (int k = 0; k < strlen(vowels); k++) {
                  if (ar[i][j] == vowels[k]) {
                      ar[i][j] = '*';
                      count++;
                      break;
                  }
              }
          }
      }
  }
  return count;

}

//returns the longest consecutive sequence of equal numbers
int longest_equal_seq(const int* ar, int n) {
  int current_count = 1;
  int max_count = 1;
  for (int i = 1; i < n; i++) {
      if (ar[i] == ar[i-1]) {
          current_count++;
      } else {
          if (current_count > max_count) {
              max_count = current_count;
          }
          current_count = 1;
      }
  }
  if (current_count > max_count) {
      max_count = current_count;
  }
  return max_count;
}
int longest_seq(const int* ar, int n, int k) //k is the number you are searching for in a consequitive sequence
{
  int counter = 0;
  int max = 0;

  for(int i = 0; i < n; i++)
  {
    if(ar[i] == k)
    {
      counter++;
      if(counter > max)
      {
        max = counter;
      }
    }
    else
    {
      counter = 0;
    }
  }
  return max;
}

// Write a function that gets a 2-d array of ints arr[height][width], and returns 
// an array MAX of length height such that MAX[i] contains the maximal value in the 
// i’th row of the array.
int* max_row(int height, int width, int ar[height][width]) {
  int* MAX = (int*) malloc(sizeof(int) * height);

  for (int i = 0; i < height; i++) {
      int max_val = ar[i][0];
      for (int j = 1; j < width; j++) {
          if (ar[i][j] > max_val) {
              max_val = ar[i][j];
          }
      }
      MAX[i] = max_val;
  }
  return MAX;
}
// Write a function that gets a 2-d array of ints arr[height][width], 
// and returns an array SUM of length height such that SUM[i] contains the 
// sum of all values in the i’th row of the array. For example
int* sum_row(int height, int width, int ar[height][width]) {
    int* sum = (int*) malloc(height * sizeof(int)); // allocate memory for the sum array
    for (int i = 0; i < height; i++) {
        int row_sum = 0;
        for (int j = 0; j < width; j++) {
            row_sum += ar[i][j]; // add up all values in the row
        }
        sum[i] = row_sum; // store the sum of the row in the sum array
    }
    return sum; // return the sum array
}
// Write a function that gets a,b two arrays of ints of length n, and returns a new 
// array such that ret[i]=max(a[i], b[i]). For example:
// max_arrays([8,1,2,-6], [0,1,4,-2], n=4) returns [8,1,4,-2].
int* max_arrays(int* a, int* b, int n) {
  int* ret = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
          ret[i] = a[i];
      } else {
          ret[i] = b[i];
      }
  }
  return ret;
}


// Write a function that gets a string, and a char c, and 
// returns the number of substrings consisting only of c. 
// In the examples below the subsequences are marked bold.
int count_substrings(const char* str, char c) {
  int count = 0, i = 0;
  while (str[i] != '\0') {
      if (str[i] == c) {
          int j = i + 1;
          while (str[j] == c) {
              j++;
          }
          count += j - i;
          i = j;
      } else {
          i++;
      }
  }
  return count;
}

//Write a function that gets an array of strings, and a char c, 
//and counts the total number appearances of c in all strings.
int count_c(char** ar, int n, char c) {
  int count = 0;

  // Loop through each string in the array
  for (int i = 0; i < n; i++) {
    // Loop through each character in the string
    for (int j = 0; j < strlen(ar[i]); j++) {
      // If the character matches c, increment the count
      if (ar[i][j] == c) {
        count++;
      }
    }
  }

  return count;
}

// Write a function that gets two arrays of ints and counts how many elements 
// appear in both arrays. You may assume all values in each array are different.
int count_common(const int* ar1, int n, const int* ar2, int n2) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n2; j++) {
            if (ar1[i] == ar2[j]) {
                count++;
                found = true;
                break;
            }
        }
        if (found) {
            continue;
        }
    }
    return count;
}

// Write a function that gets two strings, str1 and str2, and searches for 
// str2 inside str1, and returns the index of the first appearance of str2 in str1. 
// If str is not in str, the function returns -1. 
int str_find(const char* str1, const char* str2) {
  int str1_len = strlen(str1);
  int str2_len = strlen(str2);
  int i, j;
  for (i = 0; i <= str1_len - str2_len; i++) {
      for (j = 0; j < str2_len; j++) {
          if (str1[i + j] != str2[j]) {
              break;
          }
      }
      if (j == str2_len) {
          return i;
      }
  }
  return -1;
}

// Write a function that gets an array of strings, and reverses the array.
void rev_arr(const char** ar, int n) {
  for (int i = 0, j = n - 1; i < j; i++, j--) {
      const char* tmp = ar[i];
      ar[i] = ar[j];
      ar[j] = tmp;
  }
}

// Write a function that gets a sorted array of ints of length n>0. 
// It moves all zeros to the end of the array, keeping the relative order of all other numbers unchanged. 
// The function returns the number of zeros.
int move_zeros(int* ar, int n) {
  int zero_count = 0;
  int write_idx = 0;
  for (int i = 0; i < n; i++) {
      if (ar[i] != 0) {
          ar[write_idx++] = ar[i];
      } else {
          zero_count++;
      }
  }
  for (int i = write_idx; i < n; i++) {
      ar[i] = 0;
  }
  return zero_count;
}